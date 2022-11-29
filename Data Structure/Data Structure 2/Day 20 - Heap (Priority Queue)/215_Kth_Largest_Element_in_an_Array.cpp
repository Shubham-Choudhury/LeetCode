// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto n : nums) {
            pq.push(n);
        }
        while (k > 1) {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << s.findKthLargest(nums, 2);
    return 0;
}