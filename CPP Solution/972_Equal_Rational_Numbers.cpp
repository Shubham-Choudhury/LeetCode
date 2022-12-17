// Link: https://leetcode.com/problems/equal-rational-numbers/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
    bool isRationalEqual(string S, string T)
    {
        return getRational(S) == getRational(T);
    }

    double getRational(string S)
    {
        int pos = S.find('(');
        if (pos == string::npos)
        {
            return stod(S);
        }
        string base = S.substr(0, pos);
        string repeat = S.substr(pos + 1, S.size() - pos - 2);
        for (int i = 0; i < 20; i++)
        {
            base += repeat;
        }
        return stod(base);
    }
};

int main()
{
    Solution sol;
    string S = "0.(52)";
    string T = "0.5(25)";
    cout << sol.isRationalEqual(S, T) << endl;
    return 0;
}
