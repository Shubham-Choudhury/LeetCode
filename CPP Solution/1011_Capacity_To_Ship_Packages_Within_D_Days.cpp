// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int D)
    {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int need = 1;
            int cur = 0;
            for (int i = 0; i < weights.size(); i++)
            {
                if (cur + weights[i] > mid)
                {
                    need++;
                    cur = 0;
                }
                cur += weights[i];
            }
            if (need <= D)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main()
{
    Solution sol;
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int D = 5;
    cout << sol.shipWithinDays(weights, D) << endl;
    return 0;
}
