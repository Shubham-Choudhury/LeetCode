// Link: https://leetcode.com/problems/rotate-list/?envType=study-plan&id=programming-skills-ii

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode* temp = head;
        int len = 1;
        while (temp->next != NULL) {
            temp = temp->next;
            len++;
        }
        temp->next = head;
        k = k % len;
        k = len - k;
        while (k--) {
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* result = s.rotateRight(head, 2);
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}