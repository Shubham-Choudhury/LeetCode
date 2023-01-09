// Link: https://leetcode.com/problems/design-a-stack-with-increment-operation/

#include <bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    vector<int> stack;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        if (stack.size() == 0) {
            return -1;
        }
        int ans = stack.back();
        stack.pop_back();
        return ans;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, (int)stack.size()); i++) {
            stack[i] += val;
        }
    }
};

int main(){
    CustomStack *obj = new CustomStack(3);
    obj->push(1);
    obj->push(2);
    cout << obj->pop() << endl;
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->increment(5, 100);
    obj->increment(2, 100);
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    return 0;
}