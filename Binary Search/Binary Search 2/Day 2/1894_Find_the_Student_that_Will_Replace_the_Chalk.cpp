// Link: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for (int i = 0; i < chalk.size(); i++) {
            sum += chalk[i];
        }
        k %= sum;
        for (int i = 0; i < chalk.size(); i++) {
            if (chalk[i] > k) {
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> chalk = {5, 1, 5};
    cout << s.chalkReplacer(chalk, 22) << endl;
    return 0;
}