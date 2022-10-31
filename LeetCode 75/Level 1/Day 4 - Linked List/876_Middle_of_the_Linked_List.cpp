// Link: https://leetcode.com/problems/middle-of-the-linked-list/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    ListNode* ans = obj.middleNode(head);
    cout << ans->val << endl;
    return 0;
}

