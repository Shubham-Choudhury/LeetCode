// Link: https://leetcode.com/problems/isomorphic-strings/?envType=study-plan&id=level-1

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s2t[256] = {0};
        int t2s[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            if (s2t[s[i]] == 0 && t2s[t[i]] == 0) {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            } else if (s2t[s[i]] != t[i] || t2s[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    string s1 = "egg";
    string t1 = "add";
    cout << s.isIsomorphic(s1, t1) << endl;
    string s2 = "foo";
    string t2 = "bar";
    cout << s.isIsomorphic(s2, t2) << endl;
    string s3 = "paper";
    string t3 = "title";
    cout << s.isIsomorphic(s3, t3) << endl;
    return 0;
}