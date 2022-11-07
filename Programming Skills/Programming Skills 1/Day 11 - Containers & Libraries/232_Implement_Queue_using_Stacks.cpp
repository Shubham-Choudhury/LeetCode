// Link: https://leetcode.com/problems/implement-queue-using-stacks/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result = peek();
        st2.pop();
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        if(st2.empty()) {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

int main() {
    MyQueue obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    cout << obj.pop() << endl;
    cout << obj.peek() << endl;
    cout << obj.empty() << endl;
    return 0;
}