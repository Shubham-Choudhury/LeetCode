// Link: https://leetcode.com/problems/generate-parentheses/?envType=study-plan&id=algorithm-ii

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0) {
            return res;
        }
        string path = "";
        dfs(n, n, path, res);
        return res;
    }
    
    void dfs(int left, int right, string path, vector<string> &res) {
        if(left == 0 && right == 0) {
            res.push_back(path);
            return;
        }
        if(left > 0) {
            path.push_back('(');
            dfs(left - 1, right, path, res);
            path.pop_back();
        }
        if(right > left) {
            path.push_back(')');
            dfs(left, right - 1, path, res);
            path.pop_back();
        }
    }
};

int main() {
    int n = 3;
    Solution s;
    vector<string> res = s.generateParenthesis(n);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}