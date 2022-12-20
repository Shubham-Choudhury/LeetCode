// Link: https://leetcode.com/problems/maximum-width-of-binary-tree/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        dfs(root, 0, 0); // position of this node and the current depth
        return maxWidth;
    }

private:
    int maxWidth = INT_MIN;
    unordered_map<int, unsigned long int> leftPosition; //[depth] : [leftmostnode Position]
    void dfs(TreeNode *root, unsigned long int position, int depth)
    {
        if (root == nullptr)
            return;

        // Only if a leftModeNode position is not already present at this depth
        if (leftPosition.count(depth) == 0)
        {
            leftPosition[depth] = position;
        }

        int leftMostposition = leftPosition[depth];
        /*Calculate the max width*/
        int widthAtCurrentDepth = position - leftMostposition + 1;
        maxWidth = max(maxWidth, widthAtCurrentDepth);

        dfs(root->left, position * 2, depth + 1);
        dfs(root->right, position * 2 + 1, depth + 1);
    }
};

int main(void)
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    cout << sol.widthOfBinaryTree(root) << endl;
    return 0;
}
