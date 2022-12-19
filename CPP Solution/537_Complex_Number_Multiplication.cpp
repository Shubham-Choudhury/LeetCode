// Link: https://leetcode.com/problems/complex-number-multiplication/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string complexNumberMultiply(string a, string b)
    {

        std::vector<int> ap;
        std::vector<int> bp;

        // find positions of +

        for (size_t i = 0; i < a.size(); i++)
        {

            if (a[i] == '+')
            {
                ap.push_back(i);
                break;
            }
        }

        for (size_t i = 0; i < b.size(); i++)
        {

            if (b[i] == '+')
            {
                bp.push_back(i);
                break;
            }
        }

        // get a1 and a2

        std::string a1;
        std::string a2;

        for (size_t i = 0; i < ap[0]; i++)
        {
            a1.push_back(a[i]);
        }

        for (size_t i = ap[0] + 1; i < a.size() - 1; i++)
        {
            a2.push_back(a[i]);
        }

        // get b1 and b2

        std::string b1;
        std::string b2;

        for (size_t i = 0; i < bp[0]; i++)
        {
            b1.push_back(b[i]);
        }

        for (size_t i = bp[0] + 1; i < b.size() - 1; i++)
        {
            b2.push_back(b[i]);
        }

        int A1 = std::stoi(a1);
        int A2 = std::stoi(a2);
        int B1 = std::stoi(b1);
        int B2 = std::stoi(b2);

        int X1 = A1 * B1 - A2 * B2;
        int X2 = A2 * B1 + A1 * B2;

        std::string res;
        res = std::to_string(X1) + "+" + std::to_string(X2) + "i";

        return res;
    }
};

int main()
{
    Solution solution;
    string a = "1+1i", b = "1+1i";
    cout << solution.complexNumberMultiply(a, b) << endl;
    return 0;
}
