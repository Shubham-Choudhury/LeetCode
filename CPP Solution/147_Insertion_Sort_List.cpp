// Link: https://leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = head;
        while (cur) {
            ListNode* pre = dummy;
            while (pre->next && pre->next->val < cur->val) {
                pre = pre->next;
            }
            ListNode* next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = next;
        }
        return dummy->next;
    }
};

int main()
{
    Solution a;
    ListNode *b = new ListNode(4);
    ListNode *c = new ListNode(2);
    ListNode *d = new ListNode(1);
    ListNode *e = new ListNode(3);
    b->next = c;
    c->next = d;
    d->next = e;
    ListNode *f = a.insertionSortList(b);
    while (f) {
        cout << f->val << " ";
        f = f->next;
    }
    cout << endl;
    return 0;
}
