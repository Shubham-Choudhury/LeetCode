// Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

#include <bits/stdc++.h>
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

class FindElements
{
    unordered_set<int> s;

public:
    FindElements(TreeNode *root)
    {
        root->val = 0;
        s.insert(0);
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
            {
                node->left->val = 2 * node->val + 1;
                s.insert(node->left->val);
                q.push(node->left);
            }
            if (node->right)
            {
                node->right->val = 2 * node->val + 2;
                s.insert(node->right->val);
                q.push(node->right);
            }
        }
    }

    bool find(int target)
    {
        return s.find(target) != s.end();
    }
};

int main(){
    TreeNode *root = new TreeNode(-1);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(-1);
    root->left->left = new TreeNode(-1);
    root->left->right = new TreeNode(-1);
    root->right->left = new TreeNode(-1);
    root->right->right = new TreeNode(-1);
    FindElements *obj = new FindElements(root);
    cout << obj->find(1) << endl;
    cout << obj->find(3) << endl;
    cout << obj->find(5) << endl;
    cout << obj->find(7) << endl;
    return 0;
    
}
