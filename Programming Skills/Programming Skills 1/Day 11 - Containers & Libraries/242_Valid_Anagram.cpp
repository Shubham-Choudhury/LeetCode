// Link: https://leetcode.com/problems/valid-anagram/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26);
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            v[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (v[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    Solution obj;
    cout << obj.isAnagram(s, t) << endl;
    return 0;
}