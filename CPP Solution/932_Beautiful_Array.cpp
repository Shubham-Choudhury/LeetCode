// Link: https://leetcode.com/problems/beautiful-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> beautifulArray(int N)
    {
        vector<int> res = {1};
        while (res.size() < N)
        {
            vector<int> tmp;
            for (int i : res)
                if (i * 2 - 1 <= N)
                    tmp.push_back(i * 2 - 1);
            for (int i : res)
                if (i * 2 <= N)
                    tmp.push_back(i * 2);
            res = tmp;
        }
        return res;
    }
};

int main()
{
    Solution S;
    int N = 4;
    vector<int> res = S.beautifulArray(N);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
