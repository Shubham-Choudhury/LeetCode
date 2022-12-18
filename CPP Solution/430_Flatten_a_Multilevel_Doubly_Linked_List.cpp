// Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        Node *p = head;
        while (p != nullptr)
        {
            if (p->child != nullptr)
            {
                Node *next = p->next;
                Node *child = flatten(p->child);
                p->next = child;
                child->prev = p;
                p->child = nullptr;
                while (p->next != nullptr)
                    p = p->next;
                p->next = next;
                if (next != nullptr)
                    next->prev = p;
            }
            p = p->next;
        }
        return head;
    }
};

int main()
{
    Solution s;
    s.flatten(nullptr);
    return 0;
}