// Link: https://leetcode.com/problems/lru-cache/

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        update(key);
        return m[key].first;
    }
    
    void put(int key, int value) {
        if (m.find(key) == m.end()) {
            if (m.size() == cap) {
                m.erase(q.back());
                q.pop_back();
            }
        } else {
            q.erase(m[key].second);
        }
        q.push_front(key);
        m[key] = {value, q.begin()};
    }

private:
    int cap;
    list<int> q;
    unordered_map<int, pair<int, list<int>::iterator>> m;
    void update(int key) {
        q.erase(m[key].second);
        q.push_front(key);
        m[key].second = q.begin();
    }
};

int main()
{
    LRUCache a(2);
    a.put(1, 1);
    a.put(2, 2);
    cout << a.get(1) << endl;
    a.put(3, 3);
    cout << a.get(2) << endl;
    a.put(4, 4);
    cout << a.get(1) << endl;
    cout << a.get(3) << endl;
    cout << a.get(4) << endl;
}
