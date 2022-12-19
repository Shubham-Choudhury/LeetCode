// Link: https://leetcode.com/problems/random-flip-matrix/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    map<pair<int, int>, int> temp;
    int row;
    int col;
    Solution(int n_rows, int n_cols)
    {
        row = n_rows;
        col = n_cols;
    }

    vector<int> flip()
    {
        int total = row * col;
        int ok = rand() % total;
        int r = ok / col;
        int c = ok % col;
        pair<int, int> temp1 = {r, c};
        while (temp[temp1] != 0)
        {
            ok = rand() % total;
            r = ok / col;
            c = ok % col;
            temp1 = {r, c};
        }
        temp[temp1] = 1;
        vector<int> ans = {r, c};
        return ans;
    }

    void reset()
    {
        temp.clear();
    }
};

int main()
{
    Solution s(2, 2);
    for (int i = 0; i < 4; i++)
    {
        vector<int> v = s.flip();
        cout << v[0] << " " << v[1] << endl;
    }
    s.reset();
    for (int i = 0; i < 4; i++)
    {
        vector<int> v = s.flip();
        cout << v[0] << " " << v[1] << endl;
    }
    return 0;
}
