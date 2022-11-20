// Link: https://leetcode.com/problems/swap-nodes-in-pairs/?envType=study-plan&id=data-structure-ii

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;
        ListNode* next = head->next;
        while(cur != NULL && next != NULL) {
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
            prev = cur;
            cur = cur->next;
            if(cur != NULL) {
                next = cur->next;
            }
        }
        return dummy->next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution s;
    ListNode* res = s.swapPairs(head);
    while(res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}