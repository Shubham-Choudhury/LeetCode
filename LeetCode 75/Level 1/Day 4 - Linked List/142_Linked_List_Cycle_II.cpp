// https://leetcode.com/problems/linked-list-cycle-ii/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

int main(){
    ListNode* head = new ListNode(3);
    ListNode* temp = head;
    temp->next = new ListNode(2);
    temp = temp->next;
    temp->next = new ListNode(0);
    temp = temp->next;
    temp->next = new ListNode(-4);
    temp = temp->next;
    temp->next = head->next;
    Solution obj;
    ListNode* ans = obj.detectCycle(head);
    cout << ans->val << endl;
    return 0;
}