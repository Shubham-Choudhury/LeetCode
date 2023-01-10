// Link: https://leetcode.com/problems/queries-on-a-permutation-with-key/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> processQueries(vector<int> &queries, int m)
    {

        vector<int> P;
        vector<int> ans;
        for (int i = 1; i <= m; i++)
        {
            P.push_back(i);
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int index = 0;
            for (int j = 0; j < P.size(); j++)
            {
                if (P[j] == queries[i])
                {
                    index = j;
                    break;
                }
            }
            ans.push_back(index);
            P.erase(P.begin() + index);
            P.insert(P.begin(), queries[i]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> queries = {3, 1, 2, 1};
    int m = 5;
    vector<int> ans = sol.processQueries(queries, m);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}