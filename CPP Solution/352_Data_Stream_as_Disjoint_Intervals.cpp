// Link: https://leetcode.com/problems/data-stream-as-disjoint-intervals/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class SummaryRanges {
    set<int> vals;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) { // O(logN)
        vals.insert(val);
    }
    
    vector<vector<int>> getIntervals() { // O(N) https://stackoverflow.com/a/11780212/2692667
        vector<vector<int>> ans;
        
        if (vals.size() == 0) {
            return ans;
        }
        
        ans.push_back({*vals.begin(), *vals.begin()});

        for (auto it = next(vals.begin()); it != vals.end(); it++) {
            if (*it == ans.back()[1] + 1) {
                ans.back()[1] = *it;
            } else {
                ans.push_back({*it, *it});
            }
        }
        
        return ans;
    }
};

int main() {
    SummaryRanges obj;
    vector<vector<int>> res;
    
    obj.addNum(1);
    obj.addNum(3);
    obj.addNum(7);
    obj.addNum(2);
    obj.addNum(6);
    res = obj.getIntervals();
    for (auto v : res)
        cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl;
    
    obj.addNum(4);
    res = obj.getIntervals();
    for (auto v : res)
        cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl;
    
    obj.addNum(5);
    res = obj.getIntervals();
    for (auto v : res)
        cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl;
    
    obj.addNum(8);
    res = obj.getIntervals();
    for (auto v : res)
        cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl;
    
    return 0;
}

