// Link: https://leetcode.com/problems/online-stock-span/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!s.empty() && s.top().first <= price) {
            span += s.top().second;
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner* obj = new StockSpanner();
    cout << obj->next(100) << endl;
    cout << obj->next(80) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(70) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(75) << endl;
    cout << obj->next(85) << endl;
    return 0;
}