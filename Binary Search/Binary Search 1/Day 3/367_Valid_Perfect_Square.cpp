// Link: https://leetcode.com/problems/valid-perfect-square/?envType=study-plan&id=binary-search-i

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int l = 1, r = num;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(mid == num / mid && num % mid == 0) return true;
            else if(mid < num / mid) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};

int main(){
    Solution s;
    cout << s.isPerfectSquare(16) << endl;
    cout << s.isPerfectSquare(14) << endl;
    return 0;
}