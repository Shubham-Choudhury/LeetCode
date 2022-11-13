// Link: https://leetcode.com/problems/sort-list/

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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        ListNode* res = merge(left, right);
        return res;
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if (left != NULL) {
            cur->next = left;
        }
        if (right != NULL) {
            cur->next = right;
        }
        return dummy->next;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    ListNode* res = s.sortList(head);
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}