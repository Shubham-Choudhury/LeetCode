// Link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

long long int traversal(struct TreeNode * root, long long * max_val, long long total_sum)
{
    if(root == NULL)
        return 0;
    
    long long int left  = traversal(root->left, max_val, total_sum);
    long long int right = traversal(root->right, max_val, total_sum);
     
    
    long long int product1 = ((left + root->val + (total_sum - left - right - root->val))) * right  ;    
    long long int product2 = (right + root->val + (total_sum - right - left - root->val) ) * left;
    
    long long max_product = product1 >= product2 ? product1 : product2;
    
    if(max_product >= *max_val)
    {
        *max_val = max_product;
    }
      
    return (left + right + root->val);
}

long long find_sum(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    long long left = find_sum(root->left);
    long long right = find_sum(root->right);
    
    return (left + right + root->val);
}

int maxProduct(struct TreeNode* root)
{
    long long max_val = INT_MIN;
    long long total_sum = find_sum(root);
    traversal(root, &max_val, total_sum);
    return max_val % ((int)pow(10, 9) + 7);
}

int main()
{
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->right->left = NULL;
    root->right->right = NULL;
    printf("%d", maxProduct(root));
    return 0;
}