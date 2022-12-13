// Link: https://leetcode.com/problems/course-schedule-iii/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        
        priority_queue<int> pq;
        int time = 0;
        for (auto &course : courses) {
            time += course[0];
            pq.push(course[0]);
            if (time > course[1]) {
                time -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};

int main() {
    Solution s;
    vector<vector<int>> courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    cout << s.scheduleCourse(courses) << endl;
    return 0;
}