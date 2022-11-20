// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) {
            return res;
        }
        vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path = "";
        dfs(digits, 0, dict, path, res);
        return res;
    }
    
    void dfs(string digits, int index, vector<string> dict, string path, vector<string> &res) {
        if(index == digits.size()) {
            res.push_back(path);
            return;
        }
        string letters = dict[digits[index] - '2'];
        for(int i = 0; i < letters.size(); i++) {
            path.push_back(letters[i]);
            dfs(digits, index + 1, dict, path, res);
            path.pop_back();
        }
    }
};

int main() {
    string digits = "23";
    Solution s;
    vector<string> res = s.letterCombinations(digits);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}