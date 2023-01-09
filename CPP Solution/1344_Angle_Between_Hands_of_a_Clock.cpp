// Link: https://leetcode.com/problems/angle-between-hands-of-a-clock/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = hour % 12 + minutes / 60.0;
        double m = minutes;
        double angle = abs(h * 30 - m * 6);
        return min(angle, 360 - angle);
    }
};

int main() {
    Solution sol;
    int hour = 12;
    int minutes = 30;
    cout << sol.angleClock(hour, minutes) << endl;
    return 0;
}
