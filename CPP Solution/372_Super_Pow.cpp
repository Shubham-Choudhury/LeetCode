// Link: https://leetcode.com/problems/super-pow/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution
{
public:
    int superPow(int a, vector<int> &b)
    {
        if (b.empty())
            return 1;
        int last = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last) % 1337;
    }

    int powmod(int a, int k)
    {
        a %= 1337;
        int res = 1;
        for (int i = 0; i < k; i++)
            res = (res * a) % 1337;
        return res;
    }
};

int main()
{
    Solution s;
    vector<int>b = {1, 0};
    cout << s.superPow(2, b) << endl;
    return 0;
}
