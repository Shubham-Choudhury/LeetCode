// Link: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/?envType=study-plan&id=binary-search-i

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++){
            int l = i, r = nums2.size() - 1;
            while (l <= r){
                int mid = l + (r - l) / 2;
                if (nums1[i] <= nums2[mid]) l = mid + 1;
                else r = mid - 1;
            }
            ans = max(ans, r - i);
        }
        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }
    Solution obj;
    cout << obj.maxDistance(nums1, nums2) << endl;
    return 0;
}