// Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return NULL;
        if (!head->next)
            return new TreeNode(head->val);
        ListNode *slow = head, *fast = head, *prev = NULL;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};

int main()
{
    Solution a;
    ListNode *b = new ListNode(1);
    b->next = new ListNode(2);
    b->next->next = new ListNode(3);
    b->next->next->next = new ListNode(4);
    b->next->next->next->next = new ListNode(5);
    b->next->next->next->next->next = new ListNode(6);

    TreeNode *c = a.sortedListToBST(b);
    return 0;
}