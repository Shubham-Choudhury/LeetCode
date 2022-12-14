// Link: https://leetcode.com/problems/rank-transform-of-a-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Disjoin Set Union-Find
    vector<int> parent;
    int dsFind(int x)
    {
        if (parent[x] != x)
            parent[x] = dsFind(parent[x]);
        return parent[x];
    }

    void dsUnion(int x, int y)
    {
        int xParent = dsFind(x);
        int yParent = dsFind(y);
        parent[xParent] = yParent;
    }

public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix)
    {
        int rSize = matrix.size();
        int cSize = matrix[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priQ;

        // Initialize parent structure for union find
        parent.resize(rSize * cSize, 0); // r * rSize + c
        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }

        // Group union by common row/col and same value

        // line sweep row
        for (int r = 0; r < rSize; r++)
        {
            unordered_map<int, int> colMap; // value, first occurance r * cSize + c
            for (int c = 0; c < cSize; c++)
            {
                int val = matrix[r][c];
                int ref = r * cSize + c;
                if (colMap.count(val))
                {
                    dsUnion(ref, colMap[val]);
                }
                else
                {
                    colMap[val] = ref;
                }
                // push the slot to priority queue at the same time
                priQ.emplace(val, ref);
            }
        }

        // line sweep col
        for (int c = 0; c < cSize; c++)
        {
            unordered_map<int, int> rowMap; // value, first occurance r * cSize + c
            for (int r = 0; r < rSize; r++)
            {
                int val = matrix[r][c];
                int ref = r * cSize + c;
                if (rowMap.count(val))
                {
                    dsUnion(ref, rowMap[val]);
                }
                else
                {
                    rowMap[val] = ref;
                }
            }
        }

        // Create a map to trace member of each union group
        unordered_map<int, vector<int>> groupMap;
        for (int i = 0; i < parent.size(); i++)
        {
            groupMap[dsFind(i)].push_back(i);
        }

        // filling in results, the value of each slot is the max (row, col) rank in each group + 1
        vector<vector<int>> res(rSize, vector<int>(cSize, -1));
        vector<int> rowMax(rSize, 0);
        vector<int> colMax(cSize, 0);
        while (!priQ.empty())
        {
            int currRef = priQ.top().second;
            priQ.pop();
            int currR = currRef / cSize;
            int currC = currRef % cSize;

            if (res[currR][currC] >= 0)
                continue;

            // for nodes in the group, find the maximum row and column
            int maxR = 0, maxC = 0;
            for (int eachRef : groupMap[dsFind(currRef)])
            {
                maxR = max(maxR, rowMax[eachRef / cSize]);
                maxC = max(maxC, colMax[eachRef % cSize]);
            }

            int rank = max(maxR, maxC) + 1;
            for (int eachRef : groupMap[dsFind(currRef)])
            {
                int eachR = eachRef / cSize;
                int eachC = eachRef % cSize;
                res[eachR][eachC] = rank;
                rowMax[eachR] = rank;
                colMax[eachC] = rank;
            }
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> b = {{1, 2}, {3, 4}};
    for (auto i : a.matrixRankTransform(b))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
