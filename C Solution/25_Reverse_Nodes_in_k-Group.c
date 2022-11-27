// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {

	if (k == 1) return head;

	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	dummy->val = -1;
	dummy->next = head;

	struct ListNode* returnHead = NULL;

	struct ListNode* start = dummy->next;
	struct ListNode* pp_prev = dummy;
	int firstTime = 1;
	while (start != NULL)
	{
		struct ListNode* end = start;

		int temp = 1;
		while (temp < k && end != NULL)
		{
			end = end->next;
			temp++;
			if (firstTime == 1)
				returnHead = end;

		}
		firstTime = 0;

		if (end == NULL) break;

		struct ListNode* aa_after = end->next;

		// REVERSE START

		pp_prev->next = NULL;
		end->next = NULL;
		struct ListNode* lastAfterReverse = start;
		struct ListNode* prev = NULL;
		struct ListNode* nnext = NULL;

		while (start != NULL)
		{
			nnext = start->next;

			start->next = prev;

			prev = start;
			start = nnext;
		}

		pp_prev->next = prev;
		lastAfterReverse->next = aa_after;

		// REVERSE END

		pp_prev = lastAfterReverse;
		start = pp_prev->next;

	}

	return returnHead;
}

int main() {
    struct ListNode *l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 1;
    l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->val = 2;
    l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->next->val = 4;
    l1->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->next->next->val = 5;
    l1->next->next->next->next->next = NULL;
    struct ListNode *l2 = reverseKGroup(l1, 2);
    while(l2 != NULL){
        printf("%d ", l2->val);
        l2 = l2->next;
    }
    return 0;
}