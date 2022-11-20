// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/?envType=study-plan&id=data-structure-ii

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr != nullptr) {
            while (curr->next != nullptr && curr->val == curr->next->val) {
                curr = curr->next;
            }
            if (prev->next == curr) {
                prev = prev->next;
            } else {
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *result = s.deleteDuplicates(head);
    cout << result << endl;
    return 0;
}