// Link: https://leetcode.com/problems/boats-to-save-people/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int n = people.size();
        int i = 0, j = n - 1;
        int ans = 0;
        while (i <= j)
        {
            if (people[i] + people[j] <= limit)
            {
                i++;
            }
            j--;
            ans++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> people = {1, 2};
    int limit = 3;
    cout << s.numRescueBoats(people, limit) << endl;
    return 0;
}
