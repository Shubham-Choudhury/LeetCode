// Link: https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool queryString(string S, int N)
    {
        for (int i = N; i > N / 2; i--)
        {
            string binary = bitset<32>(i).to_string();
            if (S.find(binary.substr(binary.find('1'))) == string::npos)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string S = "0110";
    int N = 3;
    cout << sol.queryString(S, N) << endl;
    return 0;
}
