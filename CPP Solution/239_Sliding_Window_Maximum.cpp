// Link: https://leetcode.com/problems/sliding-window-maximum/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if (dq.front() == i - k) dq.pop_front();
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution sol;
    vector<int> res = sol.maxSlidingWindow(nums, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}
