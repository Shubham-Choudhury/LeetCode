// Link: https://leetcode.com/problems/chalkboard-xor-game/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    bool xorGame(vector<int> &nums)
    {
        int n = nums.size();
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            x ^= nums[i];
        }

        if (x == 0)
            return true;

        if (n % 2 == 0)
            return true;

        return false;
    }
};

int main()
{
    Solution a;
    vector<int> in = {1, 1, 2};
    cout << a.xorGame(in) << endl;
    return 0;
}
