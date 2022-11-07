// Link: https://leetcode.com/problems/sum-of-square-numbers/?envType=study-plan&id=binary-search-i

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int s = 0, e = sqrt(c);
        while(s <= e) {
            long long p = (long long)s * s + e * e;
            if(p == c) return true;
            p < c ? s++ : e--;
        }
        return false;
    }
};

int main() {
    int c;
    cin >> c;
    Solution obj;
    cout << obj.judgeSquareSum(c) << endl;
    return 0;
}