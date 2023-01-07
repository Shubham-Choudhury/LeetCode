// Link: https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
    {
        vector<int> ans;
        if (tomatoSlices % 2 || tomatoSlices < 2 * cheeseSlices || tomatoSlices > 4 * cheeseSlices)
            return ans;
        int x = tomatoSlices / 2 - cheeseSlices;
        int y = cheeseSlices - x;
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};

int main()
{
    int tomatoSlices = 16, cheeseSlices = 7;
    Solution *obj = new Solution();
    vector<int> ans = obj->numOfBurgers(tomatoSlices, cheeseSlices);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

