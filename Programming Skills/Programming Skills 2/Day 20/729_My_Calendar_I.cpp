// Link: https://leetcode.com/problems/my-calendar-i/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto& interval : intervals) {
            if (interval.first < end && start < interval.second) {
                return false;
            }
        }
        intervals.push_back({start, end});
        return true;
    }

private:
    vector<pair<int, int>> intervals;
};

int main() {
    MyCalendar* obj = new MyCalendar();
    cout << obj->book(10, 20) << endl;
    cout << obj->book(15, 25) << endl;
    cout << obj->book(20, 30) << endl;
    return 0;
}