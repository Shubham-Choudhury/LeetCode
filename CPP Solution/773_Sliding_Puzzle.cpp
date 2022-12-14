// Link: https://leetcode.com/problems/sliding-puzzle/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        string target = "123450";
        string start = "";
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                start += to_string(board[i][j]);
        if (start == target)
            return 0;
        vector<vector<int>> dirs = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        unordered_map<string, int> mp;
        mp[start] = 0;
        queue<string> q;
        q.push(start);
        while (!q.empty())
        {
            string cur = q.front();
            q.pop();
            int zero = cur.find('0');
            for (int dir : dirs[zero])
            {
                string next = cur;
                swap(next[zero], next[dir]);
                if (mp.count(next))
                    continue;
                mp[next] = mp[cur] + 1;
                if (next == target)
                    return mp[next];
                q.push(next);
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> board = {{1, 2, 3}, {4, 0, 5}};
    Solution obj;
    cout << obj.slidingPuzzle(board) << endl;
    return 0;
}
