// Link: https://leetcode.com/problems/strictly-palindromic-number/

#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
    bool isStrictlyPalindromicNumber(int n) {
        int temp;
        string base;
        for(int i=2; i<=n-2; i++)
        {
            temp=n;
            while(temp)
            {
                base = to_string(temp%i) + base;
                temp = temp/i;
            }
        
            int sz=base.size();
            for(int j=0; j<sz; j++)
            {
                if(base[j]!=base[sz-j-1])
                    return false;    
                
            }
            base.clear();
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isStrictlyPalindromicNumber(9) << endl;
    cout << s.isStrictlyPalindromicNumber(4) << endl;
    return 0;
}