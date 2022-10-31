// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=study-plan&id=algorithm-i

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (fast == NULL) {
            return head->next;
        }
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    for(int i = 2; i <= 5; i++){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    Solution obj;
    ListNode* ans = obj.removeNthFromEnd(head, 2);
    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}