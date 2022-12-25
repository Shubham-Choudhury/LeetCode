// Link: https://leetcode.com/problems/fancy-sequence/

#include <bits/stdc++.h>
using namespace std;

class Fancy
{
public:
    vector<long long int> pre;
    vector<long long int> pros;
    vector<long long int> sums;
    int P = 1e9 + 7;
    long long expo(long long x, long long y)
    {
        long long res = 1;
        while (y > 0)
        {
            if (y & 1)
            {
                res = (res * x) % P;
            }
            y >>= 1;
            x = (x * x) % P;
        }
        return res;
    }

    Fancy()
    {
    }

    void append(int val)
    {
        pre.push_back(val);
        if (pros.empty())
        {
            pros.push_back(1);
        }
        else
        {
            pros.push_back(pros.back());
        }
        if (sums.empty())
        {
            sums.push_back(0);
        }
        else
        {
            sums.push_back(sums.back());
        }
    }

    void addAll(int inc)
    {
        if (pre.size() >= 1)
        {
            sums.back() += inc;
            sums.back() %= P;
        }
    }

    void multAll(int m)
    {
        if (pre.size() >= 1)
        {
            pros.back() *= m;
            pros.back() %= P;
            sums.back() *= m;
            sums.back() %= P;
        }
    }

    int getIndex(int idx)
    {
        if (idx >= pre.size())
            return -1;
        if (idx > 0)
        {
            long long bipro = (pros.back() * expo(pros[idx - 1], P - 2)) % P;
            long long acSum = (sums.back() - (sums[idx - 1] * bipro) % P + P) % P;
            return ((pre[idx] * bipro) % P + acSum % P) % P;
        }
        else
        {
            return (((pre[0] * pros.back()) % P + sums.back() % P) + P) % P;
        }
    }
};

int main()
{
    Fancy a;
    a.append(2);
    a.addAll(3);
    a.append(7);
    a.multAll(2);
    cout << a.getIndex(0) << endl;
    a.addAll(3);
    a.append(10);
    a.multAll(2);
    cout << a.getIndex(0) << endl;
    cout << a.getIndex(1) << endl;
    cout << a.getIndex(2) << endl;
    return 0;
}
