// Link: https://leetcode.com/problems/sort-integers-by-the-power-value/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getKth(int lo, int hi, int k)
    {
        vector<pair<int, int>> v;
        for (int i = lo; i <= hi; i++)
        {
            int count = 0;
            int num = i;
            while (num != 1)
            {
                if (num % 2 == 0)
                    num /= 2;
                else
                    num = 3 * num + 1;
                count++;
            }
            v.push_back({count, i});
        }
        sort(v.begin(), v.end());
        return v[k - 1].second;
    }
};

int main()
{
    Solution sol;
    int ans = sol.getKth(12, 15, 2);
    cout << ans << endl;
    return 0;
}
