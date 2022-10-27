// Link: https://leetcode.com/problems/minimum-window-substring/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

#define INT_MAX 2147483647;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for (int i = 0; i < t.size(); i++) {
            map[t[i]]++;
        }
        int left = 0, right = 0, count = 0, minLen = INT_MAX;
        int minLeft = 0;
        
        while (right < s.size()) {
            if (map.find(s[right]) != map.end()) {
                map[s[right]]--;
                if (map[s[right]] >= 0) {
                    count++;
                }
            }
            while (count == t.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
                if (map.find(s[left]) != map.end()) {
                    map[s[left]]++;
                    if (map[s[left]] > 0) {
                        count--;
                    }
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};

int main() {
    Solution s;
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << s.minWindow(s1, t1) << endl;
    string s2 = "a";
    string t2 = "a";
    cout << s.minWindow(s2, t2) << endl;
    return 0;
}