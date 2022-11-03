// Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/?envType=study-plan&id=algorithm-i

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        if (root->left != NULL) {
            root->left->next = root->right;
            if (root->next != NULL) {
                root->right->next = root->next->left;
            }
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};

int main() {
    Solution s;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node* root2 = s.connect(root);
    return 0;
}