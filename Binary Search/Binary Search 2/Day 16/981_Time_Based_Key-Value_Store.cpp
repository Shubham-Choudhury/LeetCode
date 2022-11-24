// Link: https://leetcode.com/problems/time-based-key-value-store/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end())
            return "";
        auto it = upper_bound(m[key].begin(), m[key].end(), make_pair(timestamp, string(101, 'z')));
        if (it == m[key].begin())
            return "";
        return prev(it)->second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> m;
};

int main() {
    TimeMap s;
    s.set("foo", "bar", 1);
    cout << s.get("foo", 1) << endl;
    cout << s.get("foo", 3) << endl;
    s.set("foo", "bar2", 4);
    cout << s.get("foo", 4) << endl;
    cout << s.get("foo", 5) << endl;
    return 0;
}