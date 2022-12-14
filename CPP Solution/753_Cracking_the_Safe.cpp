// Link: https://leetcode.com/problems/cracking-the-safe/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    string crackSafe(int n, int k)
    {
        int table[10000] = {0}, p = --k, div = pow(10, n - 1);
        table[k] = 1;
        string answer(n, '0');
        answer[n - 1] += k;

        while (true)
        {
            p = (p % div) * 10 + k;

            for (int i = k; i >= 0; i--, p--)
                if (table[p] == 0)
                {
                    table[p] = 1, answer.push_back('0' + i);
                    goto mark;
                }

            return answer;
        mark:;
        }
    }
};

int main()
{
    Solution obj;
    cout << obj.crackSafe(2, 2) << endl;
    return 0;
}