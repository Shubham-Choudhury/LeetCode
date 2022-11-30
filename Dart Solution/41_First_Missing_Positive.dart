// Link: https://leetcode.com/problems/first-missing-positive/

class Solution {
  int firstMissingPositive(List<int> nums) {
    int n = nums.length;
    for (int i = 0; i < n; i++) {
      while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
        int temp = nums[nums[i] - 1];
        nums[nums[i] - 1] = nums[i];
        nums[i] = temp;
      }
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return n + 1;
  }
}

void main() {
  var solution = Solution();
  print(solution.firstMissingPositive([1, 2, 0]));
  print(solution.firstMissingPositive([3, 4, -1, 1]));
  print(solution.firstMissingPositive([7, 8, 9, 11, 12]));
}