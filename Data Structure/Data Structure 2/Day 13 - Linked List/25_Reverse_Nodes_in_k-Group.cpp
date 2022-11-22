// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/?envType=study-plan&id=data-structure-ii

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* nodenext=NULL;
        ListNode* prevnode = NULL;
        int count=0;
        while(curr!=NULL && count<k){
            nodenext = curr->next;
            curr->next = prevnode;
            prevnode = curr;
            curr = nodenext;
            count++;
        }
        if(count!=k){
            ListNode* t = prevnode;
            prevnode = NULL;
            while(t!=NULL){
                nodenext = t->next;
                t->next = prevnode;
                prevnode = t;
                t = nodenext;
            }
            return prevnode;
        }
        if(nodenext!=NULL){
            ListNode* rest_head = reverseKGroup(nodenext , k);
            head->next = rest_head;
        }
        return prevnode;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* res = s.reverseKGroup(head, 2);
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}