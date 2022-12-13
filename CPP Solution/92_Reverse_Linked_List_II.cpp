// Link: https://leetcode.com/problems/reverse-linked-list-ii/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        for (int i = 0; i < m - 1; ++i)
            prev = prev->next;
        ListNode* cur = prev->next;
        for (int i = 0; i < n - m; ++i)
        {
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return dummy.next;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode* res = s.reverseBetween(head, 2, 4);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}