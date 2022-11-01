// Link: https://leetcode.com/problems/n-ary-tree-preorder-traversal/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> preorder(Node* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* temp = s.top();
            s.pop();
            result.push_back(temp->val);
            for(int i = temp->children.size() - 1; i >= 0; i--)
                s.push(temp->children[i]);
        }
        return result;
    }
};

int main(){
    Solution s;
    Node* root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));
    vector<int> result = s.preorder(root);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}