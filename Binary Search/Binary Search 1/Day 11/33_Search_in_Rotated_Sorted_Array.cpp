// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=study-plan&id=binary-search-i

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[l] <= nums[mid]){
                if (nums[l] <= target && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            }
            else{
                if (nums[mid] < target && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.search(nums, target) << endl;
    return 0;
}