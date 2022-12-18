// Link: https://leetcode.com/problems/construct-quad-tree/

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        return construct(grid, 0, 0, grid.size());
    }

    Node *construct(vector<vector<int>> &grid, int x, int y, int size)
    {
        if (size == 1)
        {
            return new Node(grid[x][y] == 1, true, nullptr, nullptr, nullptr, nullptr);
        }
        Node *topLeft = construct(grid, x, y, size / 2);
        Node *topRight = construct(grid, x, y + size / 2, size / 2);
        Node *bottomLeft = construct(grid, x + size / 2, y, size / 2);
        Node *bottomRight = construct(grid, x + size / 2, y + size / 2, size / 2);
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val)
        {
            return new Node(topLeft->val, true, nullptr, nullptr, nullptr, nullptr);
        }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 1, 1, 1, 0, 0, 0, 0},
                                {1, 1, 1, 1, 0, 0, 0, 0},
                                {1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 0, 0, 0, 0},
                                {1, 1, 1, 1, 0, 0, 0, 0},
                                {1, 1, 1, 1, 0, 0, 0, 0},
                                {1, 1, 1, 1, 0, 0, 0, 0}};
    Node *root = s.construct(grid);
    return 0;
}
