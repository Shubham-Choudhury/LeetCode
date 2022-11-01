// Link: https://leetcode.com/problems/ransom-note/?envType=study-plan&id=data-structure-i

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26, 0);
        for(int i = 0; i < magazine.length(); i++)
            count[magazine[i] - 'a']++;
        for(int i = 0; i < ransomNote.length(); i++)
            if(--count[ransomNote[i] - 'a'] < 0)
                return false;
        return true;
    }
};

int main(){
    Solution s;
    string ransomNote = "aa";
    string magazine = "aab";
    cout << s.canConstruct(ransomNote, magazine) << endl;
    return 0;
}