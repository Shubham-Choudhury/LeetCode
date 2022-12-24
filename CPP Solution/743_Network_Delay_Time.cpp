// Link: https://leetcode.com/problems/network-delay-time/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        // Bellman-Ford algorithm
        vector<int> waits(N, INT_MAX);
        waits[K - 1] = 0;
        // do relaxation for each edge |V|-1 times
        for (int i = 0; i < N - 1; i++)
        {
            for (auto &time : times)
            {
                // relaxation
                if (waits[time[0] - 1] != INT_MAX && waits[time[0] - 1] + time[2] < waits[time[1] - 1])
                {
                    waits[time[1] - 1] = waits[time[0] - 1] + time[2];
                }
            }
        }
        int ans = 0;
        // find the maximum time from the single source to destination
        for (auto &wait : waits)
            ans = max(ans, wait);
        // if we have any nodes not reachable, return -1
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> times;
    int n, k;
    int ans;

    // Output: 2
    times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    n = 4;
    k = 2;
    ans = sol.networkDelayTime(times, n, k);
    cout << ans << endl;

    // Output: 3
    times = {{1, 2, 1}, {2, 3, 2}, {1, 3, 4}};
    n = 3;
    k = 1;
    ans = sol.networkDelayTime(times, n, k);
    cout << ans << endl;

    // Output: -1
    times = {{1, 2, 1}};
    n = 2;
    k = 2;
    ans = sol.networkDelayTime(times, n, k);
    cout << ans << endl;

    return 0;
}
