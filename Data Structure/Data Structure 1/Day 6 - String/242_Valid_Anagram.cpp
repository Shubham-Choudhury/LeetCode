// Link: https://leetcode.com/problems/valid-anagram/?envType=study-plan&id=data-structure-i

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);
        for(int i = 0; i < s.length(); i++)
            count[s[i] - 'a']++;
        for(int i = 0; i < t.length(); i++)
            if(--count[t[i] - 'a'] < 0)
                return false;
        for(int i = 0; i < 26; i++)
            if(count[i] != 0)
                return false;
        return true;
    }
};

int main(){
    Solution s;
    string s1 = "anagram";
    string s2 = "nagaram";
    cout << s.isAnagram(s1, s2) << endl;
    return 0;
}