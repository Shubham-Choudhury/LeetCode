// Link: https://leetcode.com/problems/parsing-a-boolean-expression/

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    bool parseBoolExpr(string &expression)
    {
        size_t pos = 0; // current iteration position
        return ParseNextExpr(expression, pos);
    }

    bool ParseNextExpr(string &str, size_t &pos)
    {
        bool ret = false;
        // int bak = pos;
        switch (str[pos++])
        {
        case 't':
            ret = true;
            break;
        case 'f':
            ret = false;
            break;
        case '&':
            ret = AndExpr(str, pos);
            break;
        case '|':
            ret = OrExpr(str, pos);
            break;
        case '!':
            ret = NotExpr(str, pos);
            break;
        }
        // debug information
        // cout << ret << "\t" << str.substr(bak, pos - bak) << "\t\t" << str.substr(bak) << endl;
        return ret;
    }

    // evaluate from left to right until false appears, then jump to then end (character ')').
    bool AndExpr(string &str, size_t &pos)
    {
        bool ret = true;
        while (ret && str[pos] != ')')
            ret &= ParseNextExpr(str, ++pos);
        JumpToCurrExprEnd(str, pos);
        return ret;
    }

    // evaluate from left to right until true appears, then jump to the end (character ')').
    bool OrExpr(string &str, size_t &pos)
    {
        bool ret = false;
        while (!ret && str[pos] != ')')
            ret |= ParseNextExpr(str, ++pos);
        JumpToCurrExprEnd(str, pos);
        return ret;
    }

    // evaluate the expression between '(' and ')'
    bool NotExpr(string &str, size_t &pos)
    {
        bool ret = !ParseNextExpr(str, ++pos);
        ++pos;
        return ret;
    }

    // jump to the end of current expression and not evaluate
    void JumpToCurrExprEnd(string &str, size_t &pos)
    {
        int cnt = 1;
        while (cnt)
        {
            if (str[pos] == '(')
                ++cnt;
            else if (str[pos] == ')')
                --cnt;
            ++pos;
        }
    }
};

int main()
{
    Solution sol;
    string expression = "!(f)";
    cout << sol.parseBoolExpr(expression) << endl;
    return 0;
}
