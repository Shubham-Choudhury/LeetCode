// Link: https://leetcode.com/problems/water-and-jug-problem/?envType=study-plan&id=graph-i

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y < z)
            return false;
        if (x == z || y == z || x + y == z)
            return true;
        return z % __gcd(x, y) == 0;
    }
};

int main()
{
    Solution sol;
    int x = 3, y = 5, z = 4;
    cout << sol.canMeasureWater(x, y, z) << endl;
    return 0;
}