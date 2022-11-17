// Link: https://leetcode.com/problems/next-greater-element-ii/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> s;
        
        for (int i=0; i<nums.size()*2; i++) {
            while (!s.empty() && nums[s.top()] < nums[i%nums.size()]) {
                res[s.top()] = nums[i%nums.size()];
                s.pop();
            }
            s.push(i%nums.size());
        }
        
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,1};
    vector<int> result = s.nextGreaterElements(nums);
    for (int num : result) {
        cout << num << endl;
    }
    return 0;
}