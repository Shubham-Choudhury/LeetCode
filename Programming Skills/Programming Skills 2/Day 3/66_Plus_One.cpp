// Link: https://leetcode.com/problems/plus-one/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution obj;
    vector<int> digits = {1, 2, 3};
    vector<int> res = obj.plusOne(digits);
    for (int i : res) {
        cout << i << " ";
    }
    return 0;
}