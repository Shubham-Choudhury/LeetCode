// Link: https://leetcode.com/problems/kth-smallest-instructions/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int pascalTri[31][32] = {};

    void presolve()
    {
        pascalTri[0][0] = pascalTri[1][0] = pascalTri[1][1] = 1;
        for (int i = 2; i < 31; i++)
        {
            pascalTri[i][0] = 1;
            for (int j = 1; j <= i; j++)
            {
                pascalTri[i][j] = pascalTri[i - 1][j] + pascalTri[i - 1][j - 1];
            }
        }
    }

    string ans = "";

    void find(int numh, int numv, int k)
    {
        if (numh + numv == 0)
            return;

        long long int tempk = pascalTri[numh + numv - 1][max(numh - 1, numv)];

        if (tempk >= k)
        {
            ans.push_back('H');
            find(numh - 1, numv, k);
        }
        else
        {
            k -= tempk;
            ans.push_back('V');
            find(numh, numv - 1, k);
        }
    }

    string kthSmallestPath(vector<int> &destination, int k)
    {
        presolve();
        int numH = destination[1];
        int numV = destination[0];

        find(numH, numV, k);
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> b = {2, 3};
    cout << a.kthSmallestPath(b, 1);
    return 0;
}
