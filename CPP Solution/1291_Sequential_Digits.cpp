// Link: https://leetcode.com/problems/sequential-digits/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        for (int i = 1; i <= 9; i++)
        {
            int num = i;
            for (int j = i + 1; j <= 9; j++)
            {
                num = num * 10 + j;
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int low = 100, high = 300;
    Solution *obj = new Solution();
    vector<int> ans = obj->sequentialDigits(low, high);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
