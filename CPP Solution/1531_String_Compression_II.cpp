// Link: https://leetcode.com/problems/string-compression-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int compress(int len) {
        if (len <= 1) return len;
        return (int)log10(len) + 2;
    }
    
    int dfs(int i, int k, string &s, vector<int> &conseqLen, vector<vector<int>> &dp) {
        
        // i is out of range, is 0 length
        if (i >= s.size()) return 0;
        
        // this i, k pair has been travelled
        if (dp[i][k] != INT_MAX) return dp[i][k];
        
        int totalLen = conseqLen[i];
        int skipLen = 0;
        bool reach = true;
        int kCnt = k;
        
        while (reach) {
            
            int nextI = i + totalLen + skipLen; // starting index of next iteration
            
            // remove j characters from the current sequence
            for (int j = 0; j <= min(totalLen, kCnt); j++) {
                
                // caculate the compressed length
                int compressLen = compress(totalLen - j);
                
                // get the length of the next section
                int nextLen = dfs(nextI, kCnt - j, s, conseqLen, dp);
                
                // minimize the result
                dp[i][k] = min(dp[i][k], compressLen + nextLen);
            }
            
            // reset reach parameter, check if we can bridge another section
            reach = false;
            
            // iterate until we find a section nextI in which it has the same character
            while (nextI < s.size() && s[nextI] != s[i] && kCnt >= conseqLen[nextI]) {
                kCnt -= conseqLen[nextI];
                skipLen += conseqLen[nextI];
                nextI += conseqLen[nextI];
            }
            
            // we find a section in which we are able to bridge
            if (nextI < s.size() && s[nextI] == s[i]) {
                reach = true;
                totalLen += conseqLen[nextI];
            }
        }
        
        return dp[i][k];
    }

public:
    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> dp(s.size(), vector<int>(k + 1, INT_MAX));
        vector<int> conseqLen(s.size(), 0);
        
        // get the consequtive length of the certain index
        conseqLen.back() = 1;
        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] == s[i + 1]) {
                conseqLen[i] = conseqLen[i + 1] + 1;
            } else {
                conseqLen[i] = 1;
            }
        }
        return dfs(0, k, s, conseqLen, dp);
    }
};

int main()
{
    Solution s;
    string str = "aaabcccd";
    int k = 2;
    cout << s.getLengthOfOptimalCompression(str, k) << endl;
    return 0;
}
