// Link: https://leetcode.com/problems/word-search-ii/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (board.empty() || board[0].empty() || words.empty()) {
            return result;
        }
        int row = board.size();
        int col = board[0].size();
        Trie trie;
        for (string word : words) {
            trie.insert(word);
        }
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                findWords(board, visited, i, j, trie.root, result);
            }
        }
        return result;
    }
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string word;
    };
    struct Trie {
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        void insert(string word) {
            TrieNode* node = root;
            for (char c : word) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->word = word;
        }
    };
    void findWords(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, TrieNode* node, vector<string>& result) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col]) {
            return;
        }
        char c = board[row][col];
        if (node->children.find(c) == node->children.end()) {
            return;
        }
        node = node->children[c];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";
        }
        visited[row][col] = true;
        findWords(board, visited, row - 1, col, node, result);
        findWords(board, visited, row + 1, col, node, result);
        findWords(board, visited, row, col - 1, node, result);
        findWords(board, visited, row, col + 1, node, result);
        visited[row][col] = false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> result = s.findWords(board, words);
    for (string word : result) {
        cout << word << endl;
    }
    return 0;
}