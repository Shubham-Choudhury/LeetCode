// Link: https://leetcode.com/problems/sum-of-subarray-minimums/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);

        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            while (!st.empty() && st.top().first > arr[i])
            {
                count += st.top().second;
                st.pop();
            }
            st.push({arr[i], count});
            left[i] = count;
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            int count = 1;
            while (!st.empty() && st.top().first >= arr[i])
            {
                count += st.top().second;
                st.pop();
            }
            st.push({arr[i], count});
            right[i] = count;
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (long long)arr[i] * left[i] * right[i];
            ans %= 1000000007;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {3, 1, 2, 4};
    cout << s.sumSubarrayMins(arr) << endl;
    return 0;
}
