// Link: https://leetcode.com/problems/copy-list-with-random-pointer/

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        Node* newHead = head->next;
        Node* temp = newHead;
        curr = head;
        while (curr != NULL) {
            curr->next = curr->next->next;
            if (temp->next != NULL) {
                temp->next = temp->next->next;
            }
            curr = curr->next;
            temp = temp->next;
        }
        return newHead;
    }
};

int main() {
    Solution s;
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
    Node* res = s.copyRandomList(head);
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
}