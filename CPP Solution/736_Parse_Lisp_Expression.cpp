// Link: https://leetcode.com/problems/parse-lisp-expression/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int evaluate(string s, unordered_map<string, int> dict = unordered_map<string, int>())
    {

        if (s[0] != '(')
            return isalpha(s[0]) ? dict[s] : stoi(s);

        int i = 1;
        s.pop_back();
        string op = next(s, i);

        if (op == "let")
        {
            string var;
            do
            {
                var = next(s, i);
                if (i <= s.size())
                    dict[var] = evaluate(next(s, i), dict);
            } while (i <= s.size());

            return evaluate(var, dict);
        }
        else
        {
            int x1 = evaluate(next(s, i), dict), x2 = evaluate(next(s, i), dict);
            return op == "add" ? x1 + x2 : x1 * x2;
        }
    }

private:
    string next(const string &s, int &i)
    {
        size_t ii = i;

        if (s[i++] == '(')
        {
            for (int dif = 1; dif; ++i)
                if (s[i] == '(')
                    dif++;
                else if (s[i] == ')')
                    dif--;
        }

        else
            i = min(s.find(" ", ii), s.size());

        return s.substr(ii, i++ - ii);
    }
};

int main()
{
    Solution s;
    cout << s.evaluate("(add 1 2)") << endl;
    cout << s.evaluate("(mult 3 (add 2 3))") << endl;
    cout << s.evaluate("(let x 2 (mult x 5))") << endl;
    cout << s.evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))") << endl;
    cout << s.evaluate("(let x 3 x 2 x)") << endl;
    cout << s.evaluate("(let x 1 y 2 x (add x y) (add x y))") << endl;
    cout << s.evaluate("(let x 2 (add (let x 3 (let x 4 x)) x))") << endl;
    cout << s.evaluate("(let a1 3 b2 (add a1 1) b2)") << endl;
    return 0;
}
