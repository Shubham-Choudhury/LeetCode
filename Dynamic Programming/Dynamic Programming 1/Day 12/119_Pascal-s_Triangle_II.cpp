// Link: https://leetcode.com/problems/pascals-triangle-ii/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j >= 1; j--) {
                ans[j] += ans[j - 1];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int rowIndex = 3;
    vector<int> ans = sol.getRow(rowIndex);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}