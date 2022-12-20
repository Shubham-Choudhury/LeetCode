// Link: https://leetcode.com/problems/maximum-performance-of-a-team/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i)
        {
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, res = 0;
        for (auto &p : v)
        {
            pq.push(p.second);
            sum += p.second;
            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            res = max(res, sum * p.first);
        }
        return res % 1000000007;
    }
};

int main()
{
    Solution s;
    vector<int> speed = {2, 10, 3, 1, 5, 8};
    vector<int> efficiency = {5, 4, 3, 9, 7, 2};
    int k = 2;
    cout << s.maxPerformance(6, speed, efficiency, k) << endl;
    return 0;
}
