// Link: https://leetcode.com/problems/clone-graph/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        unordered_map<Node*, Node*> m;
        queue<Node*> q;
        q.push(node);
        m[node] = new Node(node->val);
        while (!q.empty()) {
            Node *t = q.front();
            q.pop();
            for (Node *n : t->neighbors) {
                if (m.find(n) == m.end()) {
                    m[n] = new Node(n->val);
                    q.push(n);
                }
                m[t]->neighbors.push_back(m[n]);
            }
        }
        return m[node];
    }
};

int main()
{
    Solution a;
    Node *b = new Node(1);
    Node *c = new Node(2);
    Node *d = new Node(3);
    Node *e = new Node(4);
    b->neighbors.push_back(c);
    b->neighbors.push_back(d);
    c->neighbors.push_back(b);
    c->neighbors.push_back(e);
    d->neighbors.push_back(b);
    d->neighbors.push_back(e);
    e->neighbors.push_back(c);
    e->neighbors.push_back(d);
    Node *f = a.cloneGraph(b);
    return 0;
}
