// Link: https://leetcode.com/problems/serialize-and-deserialize-bst/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "";
        ostringstream out;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node == nullptr)
                out << "null ";
            else
            {
                out << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;
        istringstream in(data);
        string val;
        in >> val;
        TreeNode *root = new TreeNode(stoi(val));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            in >> val;
            if (val != "null")
            {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            in >> val;
            if (val != "null")
            {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};

int main()
{
    Codec c;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    string data = c.serialize(root);
    cout << data << endl;
    TreeNode *newRoot = c.deserialize(data);
    cout << c.serialize(newRoot) << endl;
    return 0;
}
