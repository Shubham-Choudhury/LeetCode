// Link: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

#include <iostream>
using namespace std;

class Solution
{
public:
    int findKthNumber(int m, int n, int k)
    {
        int l = 1, r = m * n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for (int i = 1; i <= m; i++)
                cnt += min(mid / i, n);
            if (cnt < k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

int main()
{
    Solution sol;
    cout << sol.findKthNumber(3, 3, 5) << endl;
    return 0;
}
