// Link: https://leetcode.com/problems/my-calendar-ii/

#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto &i : overlaps) {
            if (i.first < end && start < i.second) {
                return false;
            }
        }
        for (auto &i : calendar) {
            if (i.first < end && start < i.second) {
                overlaps.push_back({max(i.first, start), min(i.second, end)});
            }
        }
        calendar.push_back({start, end});
        return true;
    }

private:
    vector<pair<int, int>> calendar;
    vector<pair<int, int>> overlaps;
};

int main() {
    MyCalendarTwo s;
    cout << s.book(10, 20) << endl;
    cout << s.book(50, 60) << endl;
    cout << s.book(10, 40) << endl;
    cout << s.book(5, 15) << endl;
    cout << s.book(5, 10) << endl;
    cout << s.book(25, 55) << endl;
    return 0;
}
