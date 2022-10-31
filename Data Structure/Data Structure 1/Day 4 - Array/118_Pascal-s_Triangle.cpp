// Link: https://leetcode.com/problems/pascals-triangle/?envType=study-plan&id=data-structure-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> temp(i + 1);
            temp[0] = 1;
            temp[i] = 1;
            for (int j = 1; j < i; j++) {
                temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main(){
    int numRows = 5;
    Solution obj;
    vector<vector<int>> ans = obj.generate(numRows);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}