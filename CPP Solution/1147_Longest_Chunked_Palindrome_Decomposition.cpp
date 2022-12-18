// Link: https://leetcode.com/problems/longest-chunked-palindrome-decomposition/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestDecomposition(string text) {
        if(text.size() == 1 || text.size() == 0) return text.size();
        int i = 0;
        int j = text.size()-1;
        
        int out = 0;
        while(i<=j) {
            string s1 = "";
            string s2 = "";
            
            do {
                s1 = s1 + text[i++];
                s2 = text[j--]  + s2;
                
            }while(i <= j && s1 != s2);
            if(i != j && s1 == s2) out += 2;
            else out++;
        }
        
        return out;
    }
};

int main()
{
    Solution s;
    string text = "ghiabcdefhelloadamhelloabcdefghi";
    cout << s.longestDecomposition(text) << endl;
    return 0;
}
