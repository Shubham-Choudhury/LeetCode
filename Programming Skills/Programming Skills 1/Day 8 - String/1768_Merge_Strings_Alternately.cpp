// Link: https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0;
        int j = 0;
        while(i < word1.size() && j < word2.size()) {
            ans += word1[i];
            ans += word2[j];
            i++;
            j++;
        }
        while(i < word1.size()) {
            ans += word1[i];
            i++;
        }
        while(j < word2.size()) {
            ans += word2[j];
            j++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.mergeAlternately("abc", "pqr") << endl;
    cout << s.mergeAlternately("ab", "pqrs") << endl;
    cout << s.mergeAlternately("abcd", "pq") << endl;
    return 0;
}