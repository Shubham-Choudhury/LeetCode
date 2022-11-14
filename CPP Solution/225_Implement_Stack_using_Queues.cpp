// Link: https://leetcode.com/problems/implement-stack-using-queues/

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int result = q1.front();
        q1.pop();
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return result;
    }
    
    /** Get the top element. */
    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int result = q1.front();
        q2.push(result);
        q1.pop();
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return result;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.empty() << endl;
    return 0;
}