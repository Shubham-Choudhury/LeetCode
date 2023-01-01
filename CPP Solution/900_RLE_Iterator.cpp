// Link: https://leetcode.com/problems/rle-iterator/

#include <bits/stdc++.h>
using namespace std;

class RLEIterator
{
public:
    vector<int> v;
    int i = 0;
    RLEIterator(vector<int> &A)
    {
        v = A;
    }

    int next(int n)
    {
        while (i < v.size())
        {
            if (v[i] >= n)
            {
                v[i] -= n;
                return v[i + 1];
            }
            else
            {
                n -= v[i];
                i += 2;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> A = {3, 8, 0, 9, 2, 5};
    RLEIterator rle(A);
    cout << rle.next(2) << endl;
    cout << rle.next(1) << endl;
    cout << rle.next(1) << endl;
    cout << rle.next(2) << endl;
    return 0;
}
