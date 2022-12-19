// Link: https://leetcode.com/problems/implement-rand10-using-rand7/

#include <iostream>
using namespace std;

class Solution {
public:
    int rand10() {
        int num = 40;
        while(num>=40)
        {
            num = 7*(rand7()-1) + (rand7()-1);
        }
        return num%10 + 1;
    }
};

int main()
{
    Solution s;
    cout << s.rand10() << endl;
    return 0;
}