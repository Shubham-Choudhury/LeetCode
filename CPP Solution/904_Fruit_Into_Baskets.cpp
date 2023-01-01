// Link: https://leetcode.com/problems/fruit-into-baskets/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &tree)
    {
        int n = tree.size();
        int i = 0, j = 0;
        int ans = 0;
        map<int, int> m;
        while (j < n)
        {
            m[tree[j]]++;
            while (m.size() > 2)
            {
                m[tree[i]]--;
                if (m[tree[i]] == 0)
                {
                    m.erase(tree[i]);
                }
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> tree = {1, 2, 1};
    cout << s.totalFruit(tree) << endl;
    return 0;
}
