// Link: https://leetcode.com/problems/adding-two-negabinary-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int m = arr2.size();
        int i = n - 1;
        int j = m - 1;
        int carry = 0;
        vector<int> res;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += arr1[i--];
            if (j >= 0)
                sum += arr2[j--];
            res.push_back(sum % 2);
            carry = -(sum / 2);
        }
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr1 = {1, 1, 1, 1, 1};
    vector<int> arr2 = {1, 0, 1};
    vector<int> res = sol.addNegabinary(arr1, arr2);
    for (auto &x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}

