// Link: https://leetcode.com/problems/minimum-window-substring/?envType=study-plan&id=level-2

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n == 0 || m == 0 || n < m)
            return "";
        int i = 0, j = 0;
        int result = INT_MAX;
        int start = 0;
        unordered_map<char, int> map;
        for(int k = 0; k < m; k++)
            map[t[k]]++;
        int count = map.size();
        while(j < n){
            if(map.find(s[j]) != map.end()){
                map[s[j]]--;
                if(map[s[j]] == 0)
                    count--;
            }
            while(count == 0){
                if(j - i + 1 < result){
                    result = j - i + 1;
                    start = i;
                }
                if(map.find(s[i]) != map.end()){
                    map[s[i]]++;
                    if(map[s[i]] > 0)
                        count++;
                }
                i++;
            }
            j++;
        }
        if(result == INT_MAX)
            return "";
        return s.substr(start, result);
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution obj;
    cout << obj.minWindow(s, t);
    return 0;
}