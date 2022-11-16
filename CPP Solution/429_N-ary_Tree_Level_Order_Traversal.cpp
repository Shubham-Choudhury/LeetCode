// Link: https://leetcode.com/problems/n-ary-tree-level-order-traversal/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                for (int j = 0; j < node->children.size(); j++) {
                    q.push(node->children[j]);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};

int main()
{
    Node* root = new Node(1);
    Node* node3 = new Node(3);
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    root->children.push_back(node3);
    root->children.push_back(node2);
    root->children.push_back(node4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    node3->children.push_back(node5);
    node3->children.push_back(node6);
    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}