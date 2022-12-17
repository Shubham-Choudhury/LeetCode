// Link: https://leetcode.com/problems/lexicographical-numbers/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> res;
        int cur = 1;
        for (int i = 1; i <= n; i++)
        {
            res.push_back(cur);
            if (cur * 10 <= n)
            {
                cur *= 10;
            }
            else
            {
                if (cur >= n)
                {
                    cur /= 10;
                }
                cur++;
                while (cur % 10 == 0)
                {
                    cur /= 10;
                }
            }
        }
        return res;
    }
};

void test()
{
    Solution s;
    vector<int> res = s.lexicalOrder(13);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}
