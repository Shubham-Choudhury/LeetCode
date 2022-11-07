// Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/?envType=study-plan&id=binary-search-i

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> map;
        for (int i = 0; i < nums1.size(); i++) {
            map[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (map[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                map[nums2[i]]--;
            }
        }
        return result;
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
    vector<int> result = obj.intersect(nums1, nums2);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}