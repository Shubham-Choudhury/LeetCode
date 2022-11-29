// Link: https://leetcode.com/problems/insert-delete-getrandom-o1/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end())
            return false;
        m[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end())
            return false;
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    unordered_map<int, int> m;
    vector<int> nums;
};

int main() {
    RandomizedSet* obj = new RandomizedSet();
    cout << obj->insert(1) << endl;
    cout << obj->remove(2) << endl;
    cout << obj->insert(2) << endl;
    cout << obj->getRandom() << endl;
    cout << obj->remove(1) << endl;
    cout << obj->insert(2) << endl;
    cout << obj->getRandom() << endl;
    return 0;
}
