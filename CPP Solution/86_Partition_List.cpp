// Link: https://leetcode.com/problems/partition-list/

#include <iostream>
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = head;
        while (cur != nullptr && cur->val < x)
        {
            pre = cur;
            cur = cur->next;
        }
        ListNode *pre2 = pre;
        ListNode *cur2 = cur;
        while (cur2 != nullptr)
        {
            if (cur2->val < x)
            {
                pre2->next = cur2->next;
                cur2->next = pre->next;
                pre->next = cur2;
                pre = cur2;
                cur2 = pre2->next;
            }
            else
            {
                pre2 = cur2;
                cur2 = cur2->next;
            }
        }
        return dummy->next;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    ListNode *res = s.partition(head, 3);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
