// Link: https://leetcode.com/problems/decode-ways/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int sz = s.size();
        if(sz==0 || s[0]=='0')
            return 0;
        if(sz==1)
            return 1;
        
        int dp[sz+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=sz; i++)
        {
            if(s[i-1]=='0')
            {
                if(s[i-2]=='1' || s[i-2]=='2')
                    dp[i]=dp[i-2];
                else
                    return 0;
            }
            else
            {
                if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6'))
                    dp[i]=dp[i-1]+dp[i-2];
                else
                    dp[i]=dp[i-1];
            }
        }
        return dp[sz];
    }
};

int main() {
    Solution s;
    cout << s.numDecodings("12") << endl;
    cout << s.numDecodings("226") << endl;
    cout << s.numDecodings("0") << endl;
    cout << s.numDecodings("06") << endl;
    return 0;
}