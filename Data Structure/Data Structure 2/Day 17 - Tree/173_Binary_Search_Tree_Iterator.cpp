// Link: https://leetcode.com/problems/binary-search-tree-iterator/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            stack.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* node = stack.top();
        stack.pop();
        int result = node->val;
        if (node->right) {
            node = node->right;
            while (node) {
                stack.push(node);
                node = node->left;
            }
        }
        return result;
    }
    
    bool hasNext() {
        return !stack.empty();
    }
private:
    stack<TreeNode*> stack;
};

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    BSTIterator* obj = new BSTIterator(root);
    cout << obj->next() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    return 0;
}