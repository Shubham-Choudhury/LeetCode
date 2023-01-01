// Link: https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans = 0;
        long long t = 0;
        for(auto c: s){
            long long r = t*10 + c-'0';
            if(r <= k) t = r;
            else{
                ans++;
                t = 0;
                r = c - '0';
                if(r <= k) t = r;
                else return -1;
            }
        }
        if(t <= k) ans++;
        return ans;
    }
};

int main(){
    Solution s;
    string s = "123456789";
    int k = 10;
    cout << s.minimumPartition(s, k) << endl;
    return 0;
}
