// Link: https://leetcode.com/problems/first-unique-character-in-a-string/?envType=study-plan&id=data-structure-i

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26, 0);
        for(int i = 0; i < s.length(); i++)
            count[s[i] - 'a']++;
        for(int i = 0; i < s.length(); i++)
            if(count[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};

int main(){
    Solution s;
    string s1 = "leetcode";
    cout << s.firstUniqChar(s1) << endl;
    return 0;
}