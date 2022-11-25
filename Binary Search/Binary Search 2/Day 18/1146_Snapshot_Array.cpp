// Link: https://leetcode.com/problems/snapshot-array/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> arr;
    int snap_id;
    SnapshotArray(int length) {
        arr.resize(length);
        snap_id = 0;
    }
    
    void set(int index, int val) {
        if (arr[index].empty() || arr[index].back().first != snap_id)
            arr[index].push_back({snap_id, val});
        else
            arr[index].back().second = val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, INT_MAX));
        if (it == arr[index].begin())
            return 0;
        return prev(it)->second;
    }
};

int main()
{
    SnapshotArray* obj = new SnapshotArray(3);
    obj->set(0, 5);
    cout << obj->snap() << endl;
    obj->set(0, 6);
    cout << obj->get(0, 0) << endl;
    return 0;
}