// Link: https://leetcode.com/problems/add-two-numbers-ii/

#include <iostream>
#include <stack>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* result = NULL;
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = 0;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            sum += carry;
            carry = sum / 10;
            ListNode* newnode = new ListNode(sum % 10);
            newnode->next = result;
            result = newnode;
        }
        return result;
    }
};

int main() {
    Solution s;
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode* result = s.addTwoNumbers(l1, l2);
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
