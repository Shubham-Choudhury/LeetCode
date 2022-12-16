// Link: https://leetcode.com/problems/three-equal-parts/

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> threeEqualParts(vector<int> &arr)
    {
        int ones = 0, N = arr.size();
        for (auto &x : arr)
            if (x)
                ones++;
        if (ones % 3 != 0)
            return {-1, -1};
        if (ones == 0)
            return {0, 2};
        ones /= 3;

        int zeroes = 0, i = N - 1;
        while (arr[i--] == 0)
            zeroes++;

        int si = -1, sj, j, id = 0, n;

        while (arr[id] == 0)
            si++, id++;

        n = ones;
        while (n)
            if (arr[id++] == 1)
                n--;
        i = id - 1;

        int nz = 0;
        while (arr[id] == 0)
            nz++, id++;
        if (nz < zeroes)
            return {-1, -1};
        i += zeroes, sj = id;

        n = ones;
        while (n)
            if (arr[id++] == 1)
                n--;
        j = id;

        nz = 0;
        while (arr[id] == 0)
            nz++, id++;
        if (nz < zeroes)
            return {-1, -1};
        j += zeroes;

        if (i - si != N - id || i - si != j - sj)
            return {-1, -1};

        int limit = j - sj - zeroes;
        for (int a = si + 1, b = sj, c = id; limit; a++, b++, c++, limit--)
            if (arr[a] != arr[b] || arr[a] != arr[c])
                return {-1, -1};

        return {i, j};
    }
};

int main()
{
    Solution s;
    vector<int> A = {1, 0, 1, 0, 1};
    vector<int> ret = s.threeEqualParts(A);
    for (int i = 0; i < ret.size(); ++i)
    {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}
