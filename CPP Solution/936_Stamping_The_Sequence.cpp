// Link: https://leetcode.com/problems/stamping-the-sequence/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> movesToStamp(string stamp, string target)
    {
        int n = target.size(), m = stamp.size();
        vector<int> ans;
        vector<bool> vis(n, false);
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i = 0; i <= n - m; i++)
            {
                if (vis[i])
                    continue;
                int j = 0;
                for (; j < m; j++)
                {
                    if (target[i + j] != '*' && target[i + j] != stamp[j])
                        break;
                }
                if (j == m)
                {
                    flag = true;
                    vis[i] = true;
                    ans.push_back(i);
                    for (int k = 0; k < m; k++)
                        target[i + k] = '*';
                }
            }
        }
        for (auto &x : target)
            if (x != '*')
                return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution a;
    auto b = a.movesToStamp("abc", "ababc");
    for (auto &x : b)
        cout << x << " ";
    return 0;
}
