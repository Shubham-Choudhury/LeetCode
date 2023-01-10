// Link: https://leetcode.com/problems/design-underground-system/

#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
public:
    //startStation:endStation -> {totalTime, numberOfTrips}
    unordered_map<string, pair<long long, int>> stationTimes;
    //customerId -> startStation
    unordered_map<int, pair<string,int>> inTransit;
    UndergroundSystem() {
        stationTimes.clear();
        inTransit.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        if(inTransit.find(id) != inTransit.end()) return;
        inTransit[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& info = inTransit[id];
        string startStation = info.first;
        int startTime = info.second;
        string key = startStation + ":" + stationName;
        int time = t - startTime;
        
        if(stationTimes.find(key) != stationTimes.end()) {
            auto& oldTimes = stationTimes[key];
            oldTimes.first += time;
            oldTimes.second++;
        } else {
            stationTimes[key] = {time, 1};
        }
        inTransit.erase(id);
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + ":" + endStation;
        auto& info = stationTimes[key];
        double avg = (double)info.first / (double)info.second;
        return avg;
    }
};

int main()
{
    UndergroundSystem* obj = new UndergroundSystem();
    obj->checkIn(45,"Leyton",3);
    obj->checkIn(32,"Paradise",8);
    obj->checkIn(27,"Leyton",10);
    obj->checkOut(45,"Waterloo",15);
    obj->checkOut(27,"Waterloo",20);
    obj->checkOut(32,"Cambridge",22);
    cout<<obj->getAverageTime("Paradise","Cambridge")<<endl;
    cout<<obj->getAverageTime("Leyton","Waterloo")<<endl;
    obj->checkIn(10,"Leyton",24);
    cout<<obj->getAverageTime("Leyton","Waterloo")<<endl;
    obj->checkOut(10,"Waterloo",38);
    cout<<obj->getAverageTime("Leyton","Waterloo")<<endl;
    return 0;
}