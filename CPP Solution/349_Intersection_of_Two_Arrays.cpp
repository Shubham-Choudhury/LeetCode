// Link: https://leetcode.com/problems/intersection-of-two-arrays/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<int> result;
        for (auto num : s1) {
            if (s2.find(num) != s2.end()) {
                result.push_back(num);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = s.intersection(nums1, nums2);
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}