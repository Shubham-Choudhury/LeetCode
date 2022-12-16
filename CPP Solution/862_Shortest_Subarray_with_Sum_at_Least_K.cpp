// Link: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

class Solution
{
public:
    int shortestSubarray(vector<int> &arr, int k)
    {
        deque<pair<int, long long>> dq;
        long long sum = 0;
        int ans = INT_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum >= k)
            {
                ans = min(ans, i + 1);
            }
            while (dq.size() and sum - dq.front().second >= k)
            {
                ans = min(ans, i - dq.front().first);
                dq.pop_front();
            }
            while (dq.size() and dq.back().second >= sum)
            {
                dq.pop_back();
            }
            dq.push_back({i, sum});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    vector<int> A;
    int K;

    // Output: 2
    A = {1}, K = 1;
    cout << sol.shortestSubarray(A, K) << endl;

    // Output: -1
    A = {1, 2}, K = 4;
    cout << sol.shortestSubarray(A, K) << endl;

    return 0;
}