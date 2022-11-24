// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/?envType=study-plan&id=level-2

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int result = 0;
        int i = 0, j = 0;
        unordered_set<char> set;
        while(i < n && j < n){
            if(set.find(s[j]) == set.end()){
                set.insert(s[j++]);
                result = max(result, j - i);
            }
            else
                set.erase(s[i++]);
        }
        return result;
    }
};

int main() {
    string s = "abcabcbb";
    Solution obj;
    cout << obj.lengthOfLongestSubstring(s);
    return 0;
}