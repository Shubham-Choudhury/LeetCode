// Link: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


class Solution {
public:
    bool isPossible(vector<int>& dist, double hour, int speed) {
        double time = 0;
        for(int i = 0; i < dist.size() - 1; i++) {
            time += ceil(dist[i] * 1.0 / speed);
        }
        time += (dist.back() * 1.0 / speed);
        return time <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(n - 1 >= hour) return -1;
        int l = 1, r = 1e7;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(isPossible(dist, hour, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

int main(){
    Solution s;
    vector<int> dist1 = {1, 3, 2};
    double hour1 = 6;
    vector<int> dist2 = {1, 3, 2};
    double hour2 = 2.7;
    vector<int> dist3 = {1, 3, 2};
    double hour3 = 1.9;
    cout << s.minSpeedOnTime(dist1, hour1) << endl;
    cout << s.minSpeedOnTime(dist2, hour2) << endl;
    cout << s.minSpeedOnTime(dist3, hour3) << endl;
    return 0;
}