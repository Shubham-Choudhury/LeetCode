// Link: https://leetcode.com/problems/permutation-sequence/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        getPermutation(result, nums, k);
        return result;
    }
    
    void getPermutation(string& result, vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return;
        }
        int factorial = 1;
        for (int i = 1; i < nums.size(); i++) {
            factorial *= i;
        }
        int index = (k - 1) / factorial;
        result += to_string(nums[index]);
        nums.erase(nums.begin() + index);
        getPermutation(result, nums, k - index * factorial);
    }
};

int main() {
    Solution solution;
    cout << solution.getPermutation(4, 9) << endl;
    return 0;
}