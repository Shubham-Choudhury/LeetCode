// Link: https://leetcode.com/problems/squares-of-a-sorted-array/?envType=study-plan&id=algorithm-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        vector<int> res(n);
        int k = n - 1;
        while (i <= j) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a > b) {
                res[k] = a;
                i++;
            } else {
                res[k] = b;
                j--;
            }
            k--;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> res = s.sortedSquares(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}