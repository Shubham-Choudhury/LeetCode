// Link: https://leetcode.com/problems/top-k-frequent-elements/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto n : nums)
            mp[n]++;
        priority_queue<pair<int, int>> pq;
        for (auto m : mp) {
            pq.push({m.second, m.first});
        }
        vector<int> res;
        while (k > 0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> res = s.topKFrequent(nums, 2);
    for (auto i : res)
        cout << i << " ";
    return 0;
}