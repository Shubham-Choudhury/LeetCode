// Link: https://leetcode.com/problems/complete-binary-tree-inserter/

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

class CBTInserter
{
public:
    queue<TreeNode *> q;
    TreeNode *x;
    CBTInserter(TreeNode *root)
    {
        x = root;
        q.push(root);
    }

    int insert(int val)
    {
        // if the curr node has no children then the val will be inserted to the left of the currnode

        int x;
        while (true)
        {
            TreeNode *temp = q.front();

            if (temp->left == NULL)
            {
                x = temp->val;
                temp->left = new TreeNode(val);
                q.push(temp->left);
                return x;
            }
            else if (temp->left != NULL and temp->right == NULL)
            {
                q.pop();

                x = temp->val;
                temp->right = new TreeNode(val);
                q.push(temp->left);
                q.push(temp->right);
                return x;
            }
            else if (temp->left != NULL and temp->right != NULL)
            {
                q.pop();
                q.push(temp->left);
                q.push(temp->right);
            }
        }

        return -1;
    }

    TreeNode *get_root()
    {
        return x;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    CBTInserter *obj = new CBTInserter(root);
    cout << obj->insert(7) << endl;
    cout << obj->insert(8) << endl;
    cout << obj->insert(9) << endl;
    cout << obj->insert(10) << endl;
    cout << obj->insert(11) << endl;
    cout << obj->insert(12) << endl;
    cout << obj->insert(13) << endl;
    cout << obj->insert(14) << endl;
    cout << obj->insert(15) << endl;
    cout << obj->insert(16) << endl;
    cout << obj->insert(17) << endl;
    cout << obj->insert(18) << endl;
    cout << obj->insert(19) << endl;
    cout << obj->insert(20) << endl;
    cout << obj->insert(21) << endl;
    cout << obj->insert(22) << endl;
    cout << obj->insert(23) << endl;
    cout << obj->insert(24) << endl;
    cout << obj->insert(25) << endl;
    cout << obj->insert(26) << endl;
    cout << obj->insert(27) << endl;
    cout << obj->insert(28) << endl;
    cout << obj->insert(29) << endl;
    cout << obj->insert(30) << endl;
    cout << obj->insert(31) << endl;
    cout << obj->insert(32) << endl;
    cout << obj->insert(33) << endl;
    cout << obj->insert(34) << endl;
    cout << obj->insert(35) << endl;
    cout << obj->insert(36) << endl;
    cout << obj->insert(37) << endl;
    cout << obj->insert(38) << endl;
    cout << obj->insert(39) << endl;
    cout << obj->insert(40) << endl;

    return 0;
}