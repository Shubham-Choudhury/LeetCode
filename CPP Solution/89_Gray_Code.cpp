// Link: https://leetcode.com/problems/gray-code/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> res;
        res.push_back(0);
        for (int i = 0; i < n; ++i)
        {
            int size = res.size();
            for (int j = size - 1; j >= 0; --j)
                res.push_back(res[j] | (1 << i));
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> res = s.grayCode(3);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}

