// Link: https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int BIT[30002];
    priority_queue<int, vector<int>, greater<int>> pq[10];
    vector<pair<int, int>> tmp;
    int n;

    string minInteger(string num, int k)
    {
        string res = "";
        int counter = 0;
        n = num.size();
        memset(BIT, 0, sizeof BIT);
        tmp.clear();
        for (int i = 0; i < n; i++)
            pq[num[i] - '0'].push(i);

        while (counter < n && k > 0)
        {
            for (int i = 0; i <= 9; i++)
            {
                if (!pq[i].empty())
                {
                    int cur = pq[i].top();
                    int prevCnt = getPrevCnt(cur);
                    int swaps = cur - prevCnt;
                    if (swaps <= k)
                    {
                        k -= swaps;
                        res += (i + '0');
                        pq[i].pop();
                        updateBIT(cur + 1);
                        break;
                    }
                }
            }
            counter++;
        }
        for (int i = 0; i <= 9; i++)
        {
            while (!pq[i].empty())
            {
                int num = pq[i].top();
                pq[i].pop();
                tmp.push_back({num, i});
            }
        }

        sort(tmp.begin(), tmp.end());

        for (int i = 0; i < tmp.size(); i++)
            res += (tmp[i].second + '0');

        return res;
    }

    int getPrevCnt(int x)
    {
        int cnt = 0;
        while (x > 0)
        {
            cnt += BIT[x];
            x -= (x & -x);
        }
        return cnt;
    }

    void updateBIT(int x)
    {
        while (x <= n)
        {
            BIT[x]++;
            x += (x & -x);
        }
    }
};

int main()
{
    Solution sol;
    string num, ans;
    int k;

    // Output: "2050"
    num = "4321";
    k = 4;
    ans = sol.minInteger(num, k);
    cout << ans << endl;

    // Output: "35421"
    num = "100";
    k = 1;
    ans = sol.minInteger(num, k);
    cout << ans << endl;

    // Output: "1498762550"
    num = "36789";
    k = 1000;
    ans = sol.minInteger(num, k);
    cout << ans << endl;

    // Output: "22"
    num = "22";
    k = 22;
    ans = sol.minInteger(num, k);
    cout << ans << endl;

    // Output: "5"
    num = "9438957234785635408";
    k = 23;
    ans = sol.minInteger(num, k);
    cout << ans << endl;

    return 0;
}
