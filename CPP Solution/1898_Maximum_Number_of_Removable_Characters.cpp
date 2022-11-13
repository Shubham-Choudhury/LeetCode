// Link: https://leetcode.com/problems/maximum-number-of-removable-characters/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(s[i] == t[j]) i++;
            j++;
        }
        return i == n;
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = removable.size();
        int l = 0, r = n;
        while(l < r) {
            int mid = l + (r - l + 1) / 2;
            string t = s;
            for(int i = 0; i < mid; i++) {
                t[removable[i]] = ' ';
            }
            if(isSubsequence(p, t)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};

int main(){
    Solution s;
    string s1 = "abcacb", p1 = "ab";
    vector<int> removable1 = {3, 1, 0};
    string s2 = "abcbddddd", p2 = "abcd";
    vector<int> removable2 = {3, 2, 1, 4, 5, 6};
    string s3 = "abcab", p3 = "abc";
    vector<int> removable3 = {0, 1, 2, 3, 4};
    cout << s.maximumRemovals(s1, p1, removable1) << endl;
    cout << s.maximumRemovals(s2, p2, removable2) << endl;
    cout << s.maximumRemovals(s3, p3, removable3) << endl;
    return 0;
}