// Link: https://leetcode.com/problems/shuffle-an-array/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = nums;
        for (int i = 0; i < res.size(); i++) {
            int j = rand() % (i + 1);
            swap(res[i], res[j]);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution obj(nums);
    vector<int> param_1 = obj.reset();
    vector<int> param_2 = obj.shuffle();
    for (auto i : param_1)
        cout << i << " ";
    cout << endl;
    for (auto i : param_2)
        cout << i << " ";
    return 0;
}
