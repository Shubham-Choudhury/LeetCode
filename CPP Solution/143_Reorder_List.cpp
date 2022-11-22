// Link: https://leetcode.com/problems/reorder-list/

#include <iostream>
#include <vector>
#include <queue>
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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head2;
        ListNode* nodenext = NULL;
        while(curr!=NULL){
            nodenext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nodenext;
        }
        head2 = prev;
        ListNode* c1 = head;
        ListNode* c2 = head2;
        while(c1!=NULL && c2!=NULL){
            nodenext = c1->next;
            c1->next = c2;
            c1 = nodenext;
            nodenext = c2->next;
            c2->next = c1;
            c2 = nodenext;
        }
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    s.reorderList(head);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}