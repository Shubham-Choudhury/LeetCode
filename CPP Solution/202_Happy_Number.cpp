// Link: https://leetcode.com/problems/happy-number/

#include <iostream>
using namespace std;

class Solution {
public:
    int getNext(int n) {
        int res = 0;
        while (n > 0) {
            int d = n % 10;
            res += d * d;
            n /= 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = getNext(n);
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};

int main() {
    Solution obj;
    cout << obj.isHappy(19);
    return 0;
}