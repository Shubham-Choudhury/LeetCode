// Link: https://leetcode.com/problems/poor-pigs/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int poorPigs(int n, int d, int t) {
        int cnt = t/d;
        cnt++;
        int ans = 0;
        int x = 1;
        while(x < n){
             x *= cnt;
            ans++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    int buckets = 1000;
    int minutesToDie = 15;
    int minutesToTest = 60;
    cout << s.poorPigs(buckets, minutesToDie, minutesToTest) << endl;
    return 0;
}