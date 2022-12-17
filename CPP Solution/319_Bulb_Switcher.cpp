// Link: https://leetcode.com/problems/bulb-switcher/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
using namespace std;

class Solution
{
public:
    int bulbSwitch(const int n)
    {
        return static_cast<int>(sqrt(n));
    }
};

int main()
{
    Solution solution;
    cout << solution.bulbSwitch(3) << endl;
    return 0;
}
