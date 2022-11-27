// Link: https://leetcode.com/problems/swap-nodes-in-pairs/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *p = head, *q = head;
    if(head == NULL || head->next == NULL)
        return head;
    head = head->next;
    while(q != NULL && q->next != NULL){
        p = q;
        q = q->next;
        p->next = q->next;
        q->next = p;
        q = p->next;
        if(q != NULL && q->next != NULL)
            p->next = q->next;
    }
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
    head->next->next->next->next = NULL;
    struct ListNode *result = swapPairs(head);
    while(result != NULL){
        printf("%d", result->val);
        result = result->next;
    }
    return 0;
}

