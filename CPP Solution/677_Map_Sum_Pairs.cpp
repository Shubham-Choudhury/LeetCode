// Link: https://leetcode.com/problems/map-sum-pairs/

#include <iostream>
#include <unordered_map>
using namespace std;

class MapSum
{
public:
    /** Initialize your data structure here. */
    MapSum() {}

    void insert(string key, int val)
    {
        m[key] = val;
    }

    int sum(string prefix)
    {
        int res = 0;
        for (auto x : m)
            if (x.first.substr(0, prefix.size()) == prefix)
                res += x.second;
        return res;
    }

private:
    unordered_map<string, int> m;
};

int main()
{
    MapSum obj;
    obj.insert("apple", 3);
    cout << obj.sum("ap") << endl;
    obj.insert("app", 2);
    cout << obj.sum("ap") << endl;
    return 0;
}
