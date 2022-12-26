// Link: https://leetcode.com/problems/friends-of-appropriate-ages/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int result = 0;
        vector<int> count(121, 0);
        for (auto &age : ages)
            ++count[age];
        for (int i = 15; i <= 120; ++i)
        {
            for (int j = 15; j <= 120; ++j)
            {
                if (i * 0.5 + 7 >= j)
                    continue;
                if (i < j)
                    continue;
                if (i < 100 && 100 < j)
                    continue;
                result += count[i] * (count[j] - (i == j ? 1 : 0));
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> ages;
    int result;

    // Output: 2
    ages = {16, 16};
    result = sol.numFriendRequests(ages);
    cout << result << endl;

    // Output: 2
    ages = {16, 17, 18};
    result = sol.numFriendRequests(ages);
    cout << result << endl;

    // Output: 3
    ages = {20, 30, 100, 110, 120};
    result = sol.numFriendRequests(ages);
    cout << result << endl;

    return 0;
}