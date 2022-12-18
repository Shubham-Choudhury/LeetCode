// Link: https://leetcode.com/problems/integer-replacement/

#include <iostream>
using namespace std;

class Solution
{
public:
    int integerReplacement(int n)
    {
        return countRec(n, 0);
    }

private:
    int countRec(int n, int count)
    {
        if (n == 1)
            return count;
        if (n == 3)
            return count + 2;
        if ((n & 1) == 0)
        {
            return countRec((n >> 1), count + 1);
        }
        long long a = (long long)n + 1;
        if ((a & 3) == 0)
        {
            a = a >> 1;
            return countRec((int)a, count + 2);
        }
        return countRec(n - 1, count + 1);
    }
};

int main()
{
    Solution s;
    cout << s.integerReplacement(8) << endl;
    return 0;
}
