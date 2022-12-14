// Link: https://leetcode.com/problems/my-calendar-iii/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {   
    }
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum = 0;
        int ans = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            sum += it->second;
            ans = max(ans,sum);
        }
        return ans;
    }
};

int main(){
    MyCalendarThree obj = MyCalendarThree();
    cout<<obj.book(10,20)<<endl;
    cout<<obj.book(50,60)<<endl;
    cout<<obj.book(10,40)<<endl;
    cout<<obj.book(5,15)<<endl;
    cout<<obj.book(5,10)<<endl;
    cout<<obj.book(25,55)<<endl;
    return 0;
}
