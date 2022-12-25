// Link: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> res;
        vector<int> cnt(k);
        set<int> available;
        for (int i = 0; i < k; ++i)
            available.insert(i);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < arrival.size(); ++i) {
            while (!pq.empty() && pq.top().first <= arrival[i]) {
                available.insert(pq.top().second);
                pq.pop();
            }
            if (available.empty())
                continue;
            auto it = available.lower_bound(i % k);
            if (it == available.end())
                it = available.begin();
            ++cnt[*it];
            pq.push({arrival[i] + load[i], *it});
            available.erase(it);
        }
        int max_cnt = *max_element(cnt.begin(), cnt.end());
        for (int i = 0; i < k; ++i)
            if (cnt[i] == max_cnt)
                res.push_back(i);
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> b = {1,2,3,4,5}, c = {5,2,3,3,3};
    for (auto i : a.busiestServers(3, b, c))
        cout << i << " ";
    cout << endl;
    return 0;
}
