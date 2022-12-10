// Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int madHelper(struct TreeNode* node, int min_seen, int max_seen) {
    int leftdiff,rightdiff;
    if (!(node -> val < min_seen || node -> val > max_seen))
        ;
    else {
        if (node -> val > max_seen)
            max_seen = node -> val; 
        else 
            min_seen = node -> val;    
        }
    int diff = max_seen - min_seen;
    if (node -> left == NULL && node -> right == NULL)
        return diff;
    else if (!(node -> left != NULL && node -> right != NULL)) {
        if (node -> left == NULL) {
            leftdiff = 0;
            rightdiff = madHelper(node -> right, min_seen, max_seen);
            return (rightdiff > diff ? rightdiff : diff);
        } else {
            rightdiff = 0;
            leftdiff = madHelper(node -> left, min_seen, max_seen);
            return (leftdiff > diff ? leftdiff : diff);
        }
    }
    else {
        leftdiff = madHelper(node -> left, min_seen, max_seen);
        rightdiff = madHelper(node -> right, min_seen, max_seen);
        return leftdiff > rightdiff ? leftdiff : rightdiff;
    }
}

int maxAncestorDiff(struct TreeNode* root){
    if (root == NULL)
        return 0;
    else 
        return madHelper(root, root -> val, root -> val);
}

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> val = 8;
    root -> left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> left -> val = 3;
    root -> left -> left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> left -> left -> val = 1;
    root -> left -> right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> left -> right -> val = 6;
    root -> left -> right -> left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> left -> right -> left -> val = 4;
    root -> left -> right -> right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> left -> right -> right -> val = 7;
    root -> right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> right -> val = 10;
    root -> right -> right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> right -> right -> val = 14;
    root -> right -> right -> left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> right -> right -> left -> val = 13;
    printf("%d", maxAncestorDiff(root));
    return 0;
}