// Link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

#include <iostream>
using namespace std;

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
    const unsigned int m = 1000000007;
    long long ans = 0;
    long long findTotalSum(TreeNode* root){
        if(root==NULL)
            return 0;
        
        return root->val+findTotalSum(root->left)+findTotalSum(root->right);
    }
    
    long long findSubtreeSum(TreeNode* root,long long totalsum){
        if(root==NULL)
            return 0;
        
        long long currsum = root->val+findSubtreeSum(root->left,totalsum)+findSubtreeSum(root->right,totalsum);
        
        ans = max(ans,currsum*(totalsum-currsum));
        return currsum;
        
    }
    
    int maxProduct(TreeNode* root) {
        long long totalsum = findTotalSum(root);
        
        long long subtreeSum = findSubtreeSum(root,totalsum);
        return ans%m;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    cout << s.maxProduct(root) << endl;
    return 0;
}