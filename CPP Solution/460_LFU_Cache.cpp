// Link: https://leetcode.com/problems/lfu-cache/

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> keyToValFreq;
    unordered_map<int, list<int>::iterator> keyToIter;
    unordered_map<int, list<int>> freqToKeys;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }
    
    int get(int key) {
        if (keyToValFreq.count(key) == 0) return -1;
        freqToKeys[keyToValFreq[key].second].erase(keyToIter[key]);
        keyToValFreq[key].second++;
        freqToKeys[keyToValFreq[key].second].push_front(key);
        keyToIter[key] = freqToKeys[keyToValFreq[key].second].begin();
        if (freqToKeys[minFreq].size() == 0) minFreq++;
        return keyToValFreq[key].first;
    }
    
    void put(int key, int value) {
        if (capacity <= 0) return;
        if (get(key) != -1) {
            keyToValFreq[key].first = value;
            return;
        }
        if (keyToValFreq.size() >= capacity) {
            keyToValFreq.erase(freqToKeys[minFreq].back());
            keyToIter.erase(freqToKeys[minFreq].back());
            freqToKeys[minFreq].pop_back();
        }
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
};

int main() {
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    cout << cache.get(3) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
    return 0;
}
