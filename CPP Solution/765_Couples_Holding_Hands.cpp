// Link: https://leetcode.com/problems/couples-holding-hands/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size(), cnt = 0;
        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
            pos[row[i]] = i;

        for (int i = 0; i < n; i += 2)
        {
            int x = row[i], y = x ^ 1;
            if (row[i + 1] == y)
                continue;
            ++cnt;
            int j = pos[y];
            swap(row[i + 1], row[j]);
            pos[row[i + 1]] = i + 1;
            pos[row[j]] = j;
        }
        return cnt;
    }
};

int main()
{
    vector<int> row = {0, 2, 1, 3};
    Solution obj;
    cout << obj.minSwapsCouples(row) << endl;
    return 0;
}
