// Link: https://leetcode.com/problems/verifying-an-alien-dictionary/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        if (n == 0) {
            return true;
        }
        vector<int> dict(26, 0);
        for (int i = 0; i < order.size(); i++) {
            dict[order[i] - 'a'] = i;
        }
        for (int i = 0; i < n - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int j = 0;
            while (j < word1.size() && j < word2.size()) {
                if (word1[j] != word2[j]) {
                    if (dict[word1[j] - 'a'] > dict[word2[j] - 'a']) {
                        return false;
                    }
                    break;
                }
                j++;
            }
            if (j == word2.size() && j < word1.size()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<string> words = {"hello","leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    cout << s.isAlienSorted(words, order) << endl;
    return 0;
}