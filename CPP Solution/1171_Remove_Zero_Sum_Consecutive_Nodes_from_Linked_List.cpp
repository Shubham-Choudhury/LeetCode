// Link: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode *> m;
        int sum = 0;
        for (ListNode *node = dummy; node; node = node->next)
        {
            sum += node->val;
            m[sum] = node;
        }
        sum = 0;
        for (ListNode *node = dummy; node; node = node->next)
        {
            sum += node->val;
            node->next = m[sum]->next;
        }
        return dummy->next;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);
    ListNode *res = s.removeZeroSumSublists(head);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
