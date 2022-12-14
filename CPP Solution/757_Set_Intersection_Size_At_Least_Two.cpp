// Link: https://leetcode.com/problems/set-intersection-size-at-least-two/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &ins)
    {

        sort(ins.begin(), ins.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });

        int n = 0;
        for (auto &in : ins)
        {
            while (n > 0 && in[1] <= ins[n - 1][1])
                --n;
            ins[n++] = in;
        }

        int cnt = 0;
        for (int i = 0, x = -1, y = -1; i < n; ++i)
            if (!inside(y, ins[i]))
                cnt += 2, x = ins[i][1] - 1, y = x + 1;
            else if (!inside(x, ins[i]))
                cnt++, x = y, y = ins[i][1];

        return cnt;
    }

private:
    int inside(int x, vector<int> &interval)
    {
        return x >= interval[0] && x <= interval[1];
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {1, 4}, {2, 5}, {3, 5}};
    Solution obj;
    cout << obj.intersectionSizeTwo(intervals) << endl;
    return 0;
}
