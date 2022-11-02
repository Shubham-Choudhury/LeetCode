// Link: https://leetcode.com/problems/move-zeroes/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while (i < n) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
            i++;
        }
        while (j < n) {
            nums[j] = 0;
            j++;
        }
    }
};

int main(){
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution obj;
    obj.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}