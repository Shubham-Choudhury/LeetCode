// Link: https://leetcode.com/problems/fraction-to-recurring-decimal/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";
        string res;
        if (numerator < 0 ^ denominator < 0)
            res += "-";
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        res += to_string(num / den);
        num %= den;
        if (num == 0)
            return res;
        res += ".";
        unordered_map<int, int> m;
        while (num)
        {
            if (m.find(num) != m.end())
            {
                res.insert(m[num], 1, '(');
                res += ")";
                break;
            }
            m[num] = res.size();
            num *= 10;
            res += to_string(num / den);
            num %= den;
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.fractionToDecimal(1, 2) << endl;
    cout << a.fractionToDecimal(2, 1) << endl;
    cout << a.fractionToDecimal(2, 3) << endl;
    return 0;

}