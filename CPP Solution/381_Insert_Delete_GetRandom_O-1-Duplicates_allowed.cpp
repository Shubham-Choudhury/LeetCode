// Link: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <random>
using namespace std;

class RandomizedCollection {
    unordered_map<int, unordered_set<int>> valToIdx;
    vector<int> vals;
    mt19937 rng;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        rng.seed(random_device()());
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) { // O(1)
        vals.push_back(val);
        valToIdx[val].insert(vals.size() - 1);
        return valToIdx[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) { // O(1)
        if (valToIdx.find(val) == valToIdx.end()) {
            return false;
        }
        
        int idx = *valToIdx[val].begin();
        valToIdx[val].erase(idx);
        if (valToIdx[val].size() == 0) {
            valToIdx.erase(val);
        }
        
        if (idx != vals.size() - 1) {
            int lastVal = vals.back();
            vals[idx] = lastVal;
            valToIdx[lastVal].erase(vals.size() - 1);
            valToIdx[lastVal].insert(idx);
        }
        vals.pop_back();
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() { // O(1)
        uniform_int_distribution<int> dist(0, vals.size() - 1);
        return vals[dist(rng)];
    }
};

int main(){
    RandomizedCollection obj;
    bool res;
    
    res = obj.insert(1);
    cout << res << endl;
    res = obj.insert(1);
    cout << res << endl;
    res = obj.insert(2);
    cout << res << endl;
    res = obj.insert(1);
    cout << res << endl;
    res = obj.insert(2);
    cout << res << endl;
    res = obj.insert(2);
    cout << res << endl;
    res = obj.remove(1);
    
    return 0;
}