// Link: https://leetcode.com/problems/linked-list-in-binary-tree/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool s(ListNode* h, TreeNode* r) {
        if(!h) return 1;
        if(!r) return 0;
        if(r->val == h->val) return s(h->next,r->left) || s(h->next,r->right) ;
        return 0;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return 0;
        if(s(head,root)) return 1;
        return isSubPath(head,root->left) || isSubPath(head,root->right) ;  
    }
};

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(8);
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(8);
    root->right->right = new TreeNode(1);
    root->right->right->left = new TreeNode(1);
    root->right->right->right = new TreeNode(4);
    Solution s;
    cout << s.isSubPath(head, root) << endl;
    return 0;
}