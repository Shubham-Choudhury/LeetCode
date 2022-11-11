// Link: https://leetcode.com/problems/pascals-triangle-ii/?envType=study-plan&id=data-structure-ii

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
    int rowIndex;
    vector<int> result;
    
    rowIndex = 3;
    result = sol.getRow(rowIndex);
    for (auto& i : result) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}