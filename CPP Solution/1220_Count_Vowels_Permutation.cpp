// Link: https://leetcode.com/problems/count-vowels-permutation/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <array>
#include <algorithm>
using namespace std;

constexpr int BASE = int(1e9 + 7);

class Solution
{
public:
    // a: 0, e: 1, i: 2, o: 3, u: 4
    int countVowelPermutation(int n)
    {
        vector<long> curr(5, 1); // current counts of premutations beginning with a, e, i, o, u, respectively
        vector<long> next(5, 0); // next counts of permutations with one more length

        for (int i = 1; i < n; ++i)
        {
            next[0] = curr[1];
            next[1] = curr[0] + curr[2];
            next[2] = curr[0] + curr[1] + curr[3] + curr[4];
            next[3] = curr[2] + curr[4];
            next[4] = curr[0];

            for (int j = 0; j < 5; ++j)
                next[j] %= BASE;
            swap(curr, next);
        }

        long ret = 0;
        for (int i = 0; i < 5; ++i)
            ret += curr[i];
        return ret % BASE;
    }
};

int main()
{
    Solution s;
    cout << s.countVowelPermutation(2) << endl;
    return 0;
}
