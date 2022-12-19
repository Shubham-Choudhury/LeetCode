// Link: https://leetcode.com/problems/beautiful-arrangement/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums(N);
        for (int i = 0; i < N; i++)
            nums[i] = i + 1;
        return countArrangement(nums, 0);
    }
private:
    int countArrangement(vector<int>& nums, int index) {
        if (index == nums.size())
            return 1;
        int result = 0;
        for (int i = index; i < nums.size(); i++) {
            if (nums[i] % (index + 1) == 0 || (index + 1) % nums[i] == 0) {
                swap(nums[i], nums[index]);
                result += countArrangement(nums, index + 1);
                swap(nums[i], nums[index]);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.countArrangement(2) << endl;
    return 0;
}
