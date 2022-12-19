// Link: https://leetcode.com/problems/check-if-it-is-a-good-array/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for(int i=1; i<nums.size(); i++){
            g = gcd(g,nums[i]);
        }
        return g==1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {12,5,7,23};
    cout << s.isGoodArray(nums) << endl;
    return 0;
}
