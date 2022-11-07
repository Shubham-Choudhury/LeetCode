// Link: https://leetcode.com/problems/orderly-queue/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K == 1) {
            string minStr = S;
            for (int i = 0; i < S.size(); i++) {
                string temp = S.substr(i) + S.substr(0, i);
                if (temp < minStr)
                    minStr = temp;
            }
            return minStr;
        }
        else {
            sort(S.begin(), S.end());
            return S;
        }
    }
};

int main()
{
    Solution sol;
    string S = "cba";
    int K = 1;
    cout << sol.orderlyQueue(S, K) << endl;
    return 0;
}