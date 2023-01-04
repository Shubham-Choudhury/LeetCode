// Link: https://leetcode.com/problems/next-greater-node-in-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> res;
        stack<pair<int, int>> st;
        int i = 0;
        while (head)
        {
            while (!st.empty() && st.top().second < head->val)
            {
                res[st.top().first] = head->val;
                st.pop();
            }
            st.push({i++, head->val});
            res.push_back(0);
            head = head->next;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    ListNode *head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);
    vector<int> res = sol.nextLargerNodes(head);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
