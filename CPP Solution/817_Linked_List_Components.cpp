// Link: https://leetcode.com/problems/linked-list-components/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int numComponents(ListNode *head, vector<int> &G)
    {
        unordered_set<int> s(G.begin(), G.end());
        int res = 0;
        while (head)
        {
            if (s.count(head->val) && (head->next == NULL || !s.count(head->next->val)))
            {
                res++;
            }
            head = head->next;
        }
        return res;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    vector<int> G = {0, 1, 3};
    cout << s.numComponents(head, G) << endl;
    return 0;
}