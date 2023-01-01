// Link: https://leetcode.com/problems/painting-a-grid-with-three-different-colors/

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

typedef uint64_t ull;

struct Matrix
{
    vector<vector<ull>> M;
    int N;
    Matrix(int n)
    {
        N = n;
        M = vector<vector<ull>>(n, vector<ull>(n));
    }
    Matrix operator*(const Matrix &other)
    { // overload matrix multiplication with mod
        Matrix ans(N);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                for (int k = 0; k < N; ++k)
                    ans.M[i][k] = (ans.M[i][k] + M[i][j] * other.M[j][k]) % mod;
        return ans;
    }
};

Matrix FastPower(Matrix a, ull b)
{ // fast matrix exponentiation
    Matrix ans(a.N);
    for (int i = 0; i < a.N; ++i)
        ans.M[i][i] = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

bool check(vector<int> a, vector<int> b)
{ // check if sequence A can move to sequence B
    for (int i = 0; i < a.size(); ++i)
        if (a[i] == b[i])
            return 0;
    return 1;
}

set<vector<int>> s; // store sequences from the below dfs

void dfs(vector<int> v, int n)
{ // generate all sequences
    if (v.size() == n)
    {
        s.insert(v);
        return;
    }
    v.push_back(0);
    for (int i = 1; i <= 3; ++i)
    { // use 123 for color red green blue
        v.back() = i;
        dfs(v, n);
    }
    return;
}

class Solution
{
public:
    int colorTheGrid(int n, int m)
    { // n <= 5
        s.clear();
        dfs(vector<int>(0), n);
        vector<vector<int>> valid; // store valid sequences
        for (auto v : s)
        { // filter valid sequences
            if (v.size() != n)
                continue;
            bool ok = 1;
            for (int i = 1; i < n; ++i)
            {
                if (v[i - 1] == v[i])
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                valid.push_back(v);
        }
        Matrix A(valid.size());
        for (int i = 0; i < valid.size(); ++i)
        {
            for (int j = 0; j < valid.size(); ++j)
            {
                if (check(valid[i], valid[j])) // if sequence i can move to sequence j
                    A.M[i][j] = 1;             // add an edge from sequence i to j
            }
        }
        A = FastPower(A, m - 1);
        ull ans = 0;
        for (int i = 0; i < valid.size(); ++i)
            for (int j = 0; j < valid.size(); ++j)
                ans += A.M[i][j];
        return ans % mod;
    }
};

int main()
{
    Solution s;
    cout << s.colorTheGrid(1, 1) << endl;
    cout << s.colorTheGrid(1, 2) << endl;
    cout << s.colorTheGrid(5, 5) << endl;
    return 0;
}