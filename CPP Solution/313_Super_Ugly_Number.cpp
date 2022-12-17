// Link: https://leetcode.com/problems/super-ugly-number/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution
{
public:
    int nthSuperUglyNumber(const int n, const vector<int> &primes)
    {
        typedef pair<int, int> IP;
        struct Comp
        {
            bool operator()(const IP &l, const IP &r)
            {
                return l.first > r.first;
            }
        };
        priority_queue<IP, vector<IP>, Comp> pq;
        pq.emplace(1, 0);
        for (int i = 1;; ++i)
        {
            const IP t = pq.top();
            if (i == n)
            {
                return t.first;
            }
            pq.pop();
            for (int j = t.second; j < primes.size(); ++j)
            {
                const long long lltmp = static_cast<long long>(t.first) * primes[j];
                const int itmp = static_cast<int>(lltmp);
                if (itmp != lltmp)
                {
                    // overflow, WTF
                    break;
                }
                assert(itmp > 0);
                pq.emplace(itmp, j);
            }
        }
        assert(0);
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> primes = {2, 7, 13, 19};
    cout << s.nthSuperUglyNumber(12, primes) << endl;
    return 0;
}
