// Link: https://leetcode.com/problems/reaching-points/

#include <iostream>
using namespace std;


class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == ty) break;
            if (tx > ty) {
                if (ty > sy) tx %= ty;
                else return (tx - sx) % ty == 0;
            } else {
                if (tx > sx) ty %= tx;
                else return (ty - sy) % tx == 0;
            }
        }
        return (tx == sx && ty == sy);
    }
};

int main()
{
    int sx = 1, sy = 1, tx = 3, ty = 5;
    Solution obj;
    cout << obj.reachingPoints(sx, sy, tx, ty) << endl;
    return 0;
}
