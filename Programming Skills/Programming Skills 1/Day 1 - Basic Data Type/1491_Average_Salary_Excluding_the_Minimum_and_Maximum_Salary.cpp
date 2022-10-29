// Link: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int min = salary[0];
        int max = salary[0];
        int sum = 0;
        for (int i = 0; i < salary.size(); i++) {
            if (salary[i] < min) {
                min = salary[i];
            }
            if (salary[i] > max) {
                max = salary[i];
            }
            sum += salary[i];
        }
        return (double)(sum - min - max) / (salary.size() - 2);
    }
};

int main() {
    Solution s;
    vector<int> salary = {4000, 3000, 1000, 2000};
    cout << s.average(salary) << endl;
}