// Link: https://leetcode.com/problems/3sum-with-multiplicity/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        int n = arr.size();
        int mod = 1e9 + 7;
        long long ans = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == target)
                {
                    if (arr[j] == arr[k])
                    {
                        int x = k - j + 1;
                        ans += (x * (x - 1)) / 2;
                        ans %= mod;
                        break;
                    }
                    else
                    {
                        int x = 1, y = 1;
                        while (j + 1 < k and arr[j] == arr[j + 1])
                        {
                            x++;
                            j++;
                        }
                        while (k - 1 > j and arr[k] == arr[k - 1])
                        {
                            y++;
                            k--;
                        }
                        ans += (x * y);
                        ans %= mod;
                        j++;
                        k--;
                    }
                }
                else if (sum < target)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<int> arr = {1, 1, 2, 2, 2, 2};
    int target = 5;
    cout << S.threeSumMulti(arr, target) << endl;
    return 0;
}
