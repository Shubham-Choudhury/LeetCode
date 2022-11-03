// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan&id=binary-search-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i + 1, j + 1};
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution s;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = s.twoSum(numbers, target);
    return 0;
}