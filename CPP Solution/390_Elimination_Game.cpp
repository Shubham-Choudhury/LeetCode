// Link: https://leetcode.com/problems/elimination-game/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lastRemaining(int n)
    {
        int head = 1;
        int step = 1;
        bool left = true;
        while (n > 1)
        {
            if (left || n % 2 == 1)
            {
                head += step;
            }
            n /= 2;
            step *= 2;
            left = !left;
        }
        return head;
    }
};

int main()
{
    Solution s;
    cout << s.lastRemaining(9) << endl;
    return 0;
}
