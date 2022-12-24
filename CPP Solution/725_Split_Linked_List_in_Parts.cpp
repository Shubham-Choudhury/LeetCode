// Link: https://leetcode.com/problems/split-linked-list-in-parts/

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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int n = 0;
        ListNode *cur = head;
        while (cur)
        {
            n++;
            cur = cur->next;
        }
        int width = n / k, rem = n % k;
        vector<ListNode *> ans(k, nullptr);
        cur = head;
        for (int i = 0; i < k; ++i)
        {
            ListNode *node = cur;
            for (int j = 0; j < width + (i < rem) - 1; ++j)
            {
                if (cur)
                    cur = cur->next;
            }
            if (cur)
            {
                ListNode *prev = cur;
                cur = cur->next;
                prev->next = nullptr;
            }
            ans[i] = node;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    ListNode *head;
    int k;
    vector<ListNode *> ans;

    // Output: [[1],[2],[3]]
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    k = 5;
    ans = sol.splitListToParts(head, k);
    for (auto &node : ans)
    {
        while (node)
        {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }

    // Output: [[1,2,3,4],[5,6,7],[8],[9],[10]]
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(10);
    k = 3;
    ans = sol.splitListToParts(head, k);
    for (auto &node : ans)
    {
        while (node)
        {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }

    return 0;
}