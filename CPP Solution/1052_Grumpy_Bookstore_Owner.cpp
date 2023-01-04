// Link: https://leetcode.com/problems/grumpy-bookstore-owner/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X)
    {
        int n = customers.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (grumpy[i] == 0)
                sum += customers[i];
        int mx = 0;
        for (int i = 0; i < X; i++)
            if (grumpy[i] == 1)
                mx += customers[i];
        int cur = mx;
        for (int i = X; i < n; i++)
        {
            if (grumpy[i] == 1)
                cur += customers[i];
            if (grumpy[i - X] == 1)
                cur -= customers[i - X];
            mx = max(mx, cur);
        }
        return sum + mx;
    }
};

int main()
{
    Solution sol;
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int X = 3;
    cout << sol.maxSatisfied(customers, grumpy, X) << endl;
    return 0;
}
