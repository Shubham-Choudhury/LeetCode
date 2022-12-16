// Link: https://leetcode.com/problems/single-number-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};

int main()
{
    Solution a;
    vector<int> b = {2, 2, 3, 2};
    cout << a.singleNumber(b) << endl;
    return 0;
}