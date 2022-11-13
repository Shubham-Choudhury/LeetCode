// Link: https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* res = s.oddEvenList(head);
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}