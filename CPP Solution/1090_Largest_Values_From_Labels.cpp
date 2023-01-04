// Link: https://leetcode.com/problems/largest-values-from-labels/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int num_wanted, int use_limit)
    {
        int n = values.size();
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; i++)
        {
            items[i] = {values[i], labels[i]};
        }
        sort(items.begin(), items.end(), greater<pair<int, int>>());
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n && num_wanted > 0; i++)
        {
            if (cnt[items[i].second] < use_limit)
            {
                ans += items[i].first;
                cnt[items[i].second]++;
                num_wanted--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> values, labels;
    int num_wanted, use_limit;
    cin >> num_wanted >> use_limit;
    int n;
    cin >> n;
    values.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    cin >> n;
    labels.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> labels[i];
    }
    cout << sol.largestValsFromLabels(values, labels, num_wanted, use_limit) << endl;
    return 0;
}
