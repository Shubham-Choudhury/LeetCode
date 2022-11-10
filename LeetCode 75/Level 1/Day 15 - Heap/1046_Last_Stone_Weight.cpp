// Link: https://leetcode.com/problems/last-stone-weight/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x != y) {
                pq.push(x - y);
            }
        }
        if (pq.empty()) {
            return 0;
        }
        return pq.top();
    }
};

int main() {
    Solution s;
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << s.lastStoneWeight(stones) << endl;
    return 0;
}