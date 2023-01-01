// Link: https://leetcode.com/problems/the-k-strongest-values-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getStrongest(vector<int> &arr, int k)
    {
        sort(begin(arr), end(arr));
        int i = 0, j = arr.size() - 1;
        int med = arr[(arr.size() - 1) / 2];
        while (--k >= 0)
            if (med - arr[i] > arr[j] - med)
                ++i;
            else
                --j;
        arr.erase(begin(arr) + i, begin(arr) + j + 1);
        return arr;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    vector<int> ans = s.getStrongest(arr, k);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}
