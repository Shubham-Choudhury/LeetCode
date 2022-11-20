// Link: https://leetcode.com/problems/word-search/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0) {
            return false;
        }
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dfs(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int index, int i, int j, vector<vector<bool>> &visited) {
        if(index == word.size()) {
            return true;
        }
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index]) {
            return false;
        }
        visited[i][j] = true;
        bool res = dfs(board, word, index + 1, i + 1, j, visited) || dfs(board, word, index + 1, i - 1, j, visited) || dfs(board, word, index + 1, i, j + 1, visited) || dfs(board, word, index + 1, i, j - 1, visited);
        visited[i][j] = false;
        return res;
    }
};

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    Solution s;
    cout << s.exist(board, word) << endl;
    return 0;
}   