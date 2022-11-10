// Link: https://leetcode.com/problems/design-hashmap/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<int> arr;
    MyHashMap() {
        arr.resize(1000001, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        arr[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return arr[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        arr[key] = -1;
    }
};

int main() {
    MyHashMap obj;
    obj.put(1, 1);
    obj.put(2, 2);
    cout << obj.get(1) << endl;
    cout << obj.get(3) << endl;
    obj.put(2, 1);
    cout << obj.get(2) << endl;
    obj.remove(2);
    cout << obj.get(2) << endl;
    return 0;
}