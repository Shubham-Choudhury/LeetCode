// Link: https://leetcode.com/problems/linked-list-random-node/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* head =NULL;
    //int ans = 0;
    Solution(ListNode* h) {
        head = h;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* curr= head;
        ListNode* res;
        int n=1;
        while(curr) {
            if (rand()% n == 0)
            res = curr;
            curr = curr->next;
            n++;
        }
   return res->val;
    }
};


int main()
{
    ListNode *head = new ListNode(1);
    ListNode *cur = head;
    for (int i = 2; i <= 10; i++)
    {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    Solution s(head);
    for (int i = 0; i < 10; i++)
    {
        cout << s.getRandom() << endl;
    }
    return 0;
}