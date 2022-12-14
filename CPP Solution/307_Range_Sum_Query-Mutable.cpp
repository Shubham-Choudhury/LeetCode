// Link: https://leetcode.com/problems/range-sum-query-mutable/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class NumArray {
public:
    
    struct Bucket
    {
        int sum;
        vector<int> val;
    };
    
    int bucketNum;
    int bucketSize;
    vector<Bucket> Bs;

    NumArray(vector<int> &nums) {
        int size = nums.size();
        int bucketNum = (int)sqrt(2*size);
        bucketSize = bucketNum/2;
        while(bucketSize * bucketNum<size) ++bucketSize;
        
        Bs.resize(bucketNum);
        for(int i=0, k=0; i<bucketNum; ++i)
        {
            int temp = 0;
            Bs[i].val.resize(bucketSize);
            for(int j=0; j<bucketSize && k<size; ++j, ++k)
            {
                temp += nums[k];
                Bs[i].val[j] = nums[k];
            }
            Bs[i].sum = temp;
        }
    }

    void update(int i, int val) {
        int x = i / bucketSize;
        int y = i % bucketSize;
        Bs[x].sum += (val - Bs[x].val[y]);
        Bs[x].val[y] = val;
    }

    int sumRange(int i, int j) {
        int x1 = i / bucketSize;
        int y1 = i % bucketSize;
		int x2 = j / bucketSize;
        int y2 = j % bucketSize;
        int sum = 0;

		if(x1==x2)
		{
			for(int a=y1; a<=y2; ++a)
			{
				sum += Bs[x1].val[a];
			}
			return sum;
		}

		for(int a=y1; a<bucketSize; ++a)
		{
			sum += Bs[x1].val[a];
		}
        for(int a=x1+1; a<x2; ++a)
        {
            sum += Bs[a].sum;
        }
        for(int b=0; b<=y2; ++b)
        {
            sum += Bs[x2].val[b];
        }
        return sum;
    }
};

int main()
{
    vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << endl;
    return 0;
}
