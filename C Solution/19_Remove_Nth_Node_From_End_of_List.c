// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head, *q = head;
    for(int i = 0; i < n; i++)
        q = q->next;
    if(q == NULL)
        return head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = p->next->next;
    return head;
}

int main() {
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;
    int n = 2;
    struct ListNode *result = removeNthFromEnd(head, n);
    while(result != NULL){
        printf("%d", result->val);
        result = result->next;
    }
    return 0;
}