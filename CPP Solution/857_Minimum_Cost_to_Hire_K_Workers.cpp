// Link: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <cfloat>

using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K)
    {
        int n = quality.size();
        vector<pair<double, int>> workers;
        for (int i = 0; i < n; i++)
        {
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        sort(workers.begin(), workers.end());
        priority_queue<int> pq;
        int sum = 0;
        double ans = DBL_MAX;
        for (auto worker : workers)
        {
            sum += worker.second;
            pq.push(worker.second);
            if (pq.size() > K)
            {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K)
            {
                ans = min(ans, sum * worker.first);
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    int K = 2;
    cout << solution.mincostToHireWorkers(quality, wage, K) << endl;
    return 0;
}