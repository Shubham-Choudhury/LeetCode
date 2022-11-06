// Link: https://leetcode.com/problems/merge-two-sorted-lists/?envType=study-plan&id=algorithm-i

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 != NULL) {
            cur->next = l1;
        }
        if (l2 != NULL) {
            cur->next = l2;
        }
        return head->next;
    }
};

int main() {
    Solution s;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode* l3 = s.mergeTwoLists(l1, l2);
    while (l3 != NULL) {
        cout << l3->val << " ";
        l3 = l3->next;
    }
    cout << endl;
    return 0;
}