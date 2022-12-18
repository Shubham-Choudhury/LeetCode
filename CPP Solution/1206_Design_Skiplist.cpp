// Link: https://leetcode.com/problems/design-skiplist/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Skiplist
{
private:
    struct Node
    {
        int val;
        Node *next;
        Node *down;
        Node(int v, Node *n, Node *d) : val(v), next(n), down(d) {}
    };
    Node *head;
    int level;
    int size;
    int randomLevel()
    {
        int level = 1;
        while (rand() % 2)
        {
            level++;
        }
        return level;
    }

public:
    Skiplist()
    {
        head = new Node(-1, nullptr, nullptr);
        level = 1;
        size = 0;
    }

    bool search(int target)
    {
        Node *cur = head;
        while (cur)
        {
            while (cur->next && cur->next->val < target)
            {
                cur = cur->next;
            }
            if (cur->next && cur->next->val == target)
            {
                return true;
            }
            cur = cur->down;
        }
        return false;
    }

    void add(int num)
    {
        size++;
        int curLevel = 1;
        Node *cur = head;
        vector<Node *> prevs;
        while (cur)
        {
            while (cur->next && cur->next->val < num)
            {
                cur = cur->next;
            }
            if (curLevel <= level)
            {
                prevs.push_back(cur);
            }
            cur = cur->down;
            curLevel++;
        }
        bool insertUp = true;
        Node *downNode = nullptr;
        while (insertUp && prevs.size() > 0)
        {
            cur = prevs.back();
            prevs.pop_back();
            cur->next = new Node(num, cur->next, downNode);
            downNode = cur->next;
            insertUp = (randomLevel() == level);
            level++;
        }
        if (insertUp)
        {
            head = new Node(-1, new Node(num, nullptr, downNode), head);
        }
    }

    bool erase(int num)
    {
        if (size == 0)
        {
            return false;
        }
        size--;
        Node *cur = head;
        bool exist = false;
        while (cur)
        {
            while (cur->next && cur->next->val < num)
            {
                cur = cur->next;
            }
            if (cur->next && cur->next->val == num)
            {
                exist = true;
                cur->next = cur->next->next;
            }
            cur = cur->down;
        }
        return exist;
    }
};

int main()
{
    Skiplist *obj = new Skiplist();
    bool param_1 = obj->search(1);
    obj->add(1);
    bool param_3 = obj->erase(1);
    return 0;
}
