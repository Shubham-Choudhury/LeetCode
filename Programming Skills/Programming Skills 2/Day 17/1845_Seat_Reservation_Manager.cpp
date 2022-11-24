// Link: https://leetcode.com/problems/seat-reservation-manager/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <set>
using namespace std;

class SeatManager {
public:
    set<int> s;
    SeatManager(int n) {
        for (int i = 1; i <= n; i++)
            s.insert(i);
    }
    
    int reserve() {
        int seat = *s.begin();
        s.erase(s.begin());
        return seat;
    }
    
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};

int main() {
    SeatManager s(5);
    cout << s.reserve() << " ";
    cout << s.reserve() << " ";
    s.unreserve(2);
    cout << s.reserve() << " ";
    cout << s.reserve() << " ";
    cout << s.reserve() << " ";
    cout << s.reserve() << " ";
    return 0;
}