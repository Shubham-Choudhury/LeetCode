// Link: https://leetcode.com/problems/intersection-of-two-linked-lists/?envType=study-plan&id=data-structure-ii

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (p1 != p2) {
            p1 = p1 == NULL ? headB : p1->next;
            p2 = p2 == NULL ? headA : p2->next;
        }
        return p1;
    }
};

int main() {
    Solution s;
    ListNode *headA = new ListNode(4);
    ListNode *headB = new ListNode(5);
    ListNode *result = s.getIntersectionNode(headA, headB);
    cout << result << endl;
    return 0;
}