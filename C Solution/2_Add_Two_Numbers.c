// Link: https://leetcode.com/problems/add-two-numbers/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p = result;
    int carry = 0;
    while (l1 != NULL || l2 != NULL) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = sum % 10;
    }
    if (carry != 0) {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = carry;
    }
    p->next = NULL;
    return result->next;
}

int main() {
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p = l1;
    p->val = 2;
    p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 4;
    p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 3;
    p->next = NULL;
    p = l2;
    p->val = 5;
    p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 6;
    p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 4;
    p->next = NULL;
    struct ListNode *result = addTwoNumbers(l1, l2);
    while (result != NULL) {
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}