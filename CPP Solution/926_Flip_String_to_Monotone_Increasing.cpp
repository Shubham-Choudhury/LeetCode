// Link: https://leetcode.com/problems/flip-string-to-monotone-increasing/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlipsMonoIncr(const std::string &S, int counter_one = 0, int counter_flip = 0)
    {
        for (auto ch : S)
        {
            if (ch == '1')
            {
                ++counter_one;
            }
            else
            {
                ++counter_flip;
            }
            counter_flip = std::min(counter_one, counter_flip);
        }
        return counter_flip;
    }
};

int main()
{
    Solution S;
    string s = "00110";
    cout << S.minFlipsMonoIncr(s) << endl;
    return 0;
}