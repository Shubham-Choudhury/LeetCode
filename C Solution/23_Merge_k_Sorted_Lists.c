// Link: https://leetcode.com/problems/merge-k-sorted-lists/

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p = l1, *q = l2;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *r = head;
    while(p != NULL && q != NULL){
        if(p->val < q->val){
            r->next = p;
            p = p->next;
        }
        else{
            r->next = q;
            q = q->next;
        }
        r = r->next;
    }
    if(p != NULL)
        r->next = p;
    else
        r->next = q;
    return head->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 0)
        return NULL;
    if(listsSize == 1)
        return lists[0];
    struct ListNode *p = lists[0];
    for(int i = 1; i < listsSize; i++)
        p = mergeTwoLists(p, lists[i]);
    return p;
}

int main() {
    struct ListNode *l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 1;
    l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->val = 5;
    l1->next->next->next = NULL;
    struct ListNode *l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val = 1;
    l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->val = 3;
    l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;
    struct ListNode *l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->val = 2;
    l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->next->val = 6;
    l3->next->next = NULL;
    struct ListNode *lists[3] = {l1, l2, l3};
    struct ListNode *result = mergeKLists(lists, 3);
    while(result != NULL){
        printf("%d", result->val);
        result = result->next;
    }
    return 0;
}