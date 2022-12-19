// Link: https://leetcode.com/problems/total-hamming-distance/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i < 32; i++) {
            int count = 0;
            for(auto num : nums) {
                count += (num >> i) & 1;
            }
            total += count * (nums.size() - count);
        }
        return total;
    }
};

int main()
{
    Solution s;
    vector<int> v = {4, 14, 2};
    cout << s.totalHammingDistance(v) << endl;
    return 0;
}
