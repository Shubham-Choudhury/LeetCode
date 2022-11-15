// Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/?envType=study-plan&id=algorithm-ii

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
        if (root == NULL) {
            return NULL;
        }
        Node* leftmost = root;
        while (leftmost != NULL) {
            Node* head = new Node(0);
            Node* prev = head;
            while (leftmost != NULL) {
                if (leftmost->left != NULL) {
                    prev->next = leftmost->left;
                    prev = prev->next;
                }
                if (leftmost->right != NULL) {
                    prev->next = leftmost->right;
                    prev = prev->next;
                }
                leftmost = leftmost->next;
            }
            leftmost = head->next;
        }
        return root;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    Solution s;
    Node* result = s.connect(root);
    cout << result->val << endl;
    return 0;
}