// Link: https://leetcode.com/problems/design-circular-queue/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        this->k = k;
        this->size = 0;
        this->front = 0;
        this->rear = 0;
        this->data = vector<int>(k);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        data[rear] = value;
        rear = (rear + 1) % k;
        size++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % k;
        size--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[(rear - 1 + k) % k];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == k;
    }

private:
    int k;
    int size;
    int front;
    int rear;
    vector<int> data;
};

int main() {
    MyCircularQueue* obj = new MyCircularQueue(3);
    cout << obj->enQueue(1) << endl;
    cout << obj->enQueue(2) << endl;
    cout << obj->enQueue(3) << endl;
    cout << obj->enQueue(4) << endl;
    cout << obj->Rear() << endl;
    cout << obj->isFull() << endl;
    cout << obj->deQueue() << endl;
    cout << obj->enQueue(4) << endl;
    cout << obj->Rear() << endl;
    return 0;
}
