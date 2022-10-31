// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a,int b){
   if(a%2==b%2) return a<b;
    if(a%2==1 and b%2==0){
        return false;
    }
    return true;
}

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(begin(nums),end(nums),comp);
        sort(begin(target),end(target),comp);
        long long ans=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=target[i])
                ans+=(abs(nums[i]-target[i]))/2;
        return ans/2;
    }
};

int main()
{
    Solution s;
    vector<int>nums = {8,12,6};
    vector<int>target = {2,14,10};
    cout<<s.makeSimilar(nums,target);
    return 0;
}