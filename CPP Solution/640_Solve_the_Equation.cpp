// Link: https://leetcode.com/problems/solve-the-equation/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string solveEquation(string equation)
    {
        int i = equation.find('=');
        auto left = getCoeff(equation.substr(0, i));
        auto right = getCoeff(equation.substr(i + 1));

        if (left[1] != right[1])
            return "x=" + to_string((right[0] - left[0]) / (left[1] - right[1]));
        else if (left[0] != right[0])
            return "No solution";
        else
            return "Infinite solutions";
    }

    // Get combined coefficients of 'x' and constants
    vector<int> getCoeff(string s)
    {
        s = normalize(s);
        vector<int> res(2);
        for (int i = 0, pre = 0; i < s.size(); ++i)
        {
            if (isdigit(s[i]))
                continue;
            bool isx = (s[i] == 'x');
            res[isx] += stoi(s.substr(pre, i - pre));
            pre = (i += isx);
        }
        return res;
    }

    // normalize equation by adding missing '1' coefficient for 'x'
    string normalize(string s)
    {
        string res;
        for (char c : s)
        {
            if (c == 'x' and (res.empty() or !isdigit(res.back())))
                res += '1';
            res += c;
        }
        return '0' + res + '+';
    }
};

int main()
{
    Solution s;
    cout << s.solveEquation("x+5-3+x=6+x-2") << endl;
    cout << s.solveEquation("x=x") << endl;
    cout << s.solveEquation("2x=x") << endl;
    cout << s.solveEquation("2x+3x-6x=x+2") << endl;
    cout << s.solveEquation("x=x+2") << endl;
    return 0;
}
