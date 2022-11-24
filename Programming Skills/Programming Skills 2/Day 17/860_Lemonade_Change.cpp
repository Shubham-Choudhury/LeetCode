// Link: https://leetcode.com/problems/lemonade-change/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10) {
                if (five == 0)
                    return false;
                five--;
                ten++;
            } else {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << s.lemonadeChange(bills);
    return 0;
}

