// Link: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size();
        vector<int> zrow(n), zcol(m), orow(n), ocol(m);
        // calculating number of one and zero in a row and storing that in their respective vectors
        for (int i = 0; i < n; i++)
        {
            int o = 0, z = 0;
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 0)
                    z++;
                else if (a[i][j] == 1)
                    o++;
            }
            zrow[i] = z;
            orow[i] = o;
        }
        // calculating number of one and zero in a column and storing that in their respective vectors
        for (int i = 0; i < m; i++)
        {
            int o = 0, z = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[j][i] == 0)
                    z++;
                else if (a[j][i] == 1)
                    o++;
            }
            zcol[i] = z;
            ocol[i] = o;
        }
        vector<vector<int>> ans;
        // for calculating the ans vector we simpy have ans[i][j]= onesRowi + onesColj - zerosRowi - zerosColj
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for (int j = 0; j < m; j++)
            {
                int c = 0;
                c += orow[i] + ocol[j] - zrow[i] - zcol[j];
                v.push_back(c);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a = {{1, 0, 0, 1, 0}, {0, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {1, 0, 1, 0, 1}, {1, 1, 1, 1, 0}};
    vector<vector<int>> ans = s.onesMinusZeros(a);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
