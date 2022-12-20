// Link: https://leetcode.com/problems/design-circular-deque/

#include <iostream>
using namespace std;

class MyCircularDeque
{
    int *arr;
    int front, rear, size, capacity;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k)
    {
        arr = new int[k];
        front = rear = -1;
        size = 0;
        capacity = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = value;
        size++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        size++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (isEmpty())
            return false;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        size--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if (isEmpty())
            return false;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear = (rear - 1 + capacity) % capacity;
        }
        size--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    /** Checks whether the circular deque is empty or not.*/
    bool isEmpty()
    {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        return size == capacity;
    }

    ~MyCircularDeque()
    {
        delete[] arr;
    }
};

int main()
{
    MyCircularDeque *obj = new MyCircularDeque(3);
    cout << obj->insertLast(1) << endl;
    cout << obj->insertLast(2) << endl;
    cout << obj->insertFront(3) << endl;
    cout << obj->insertFront(4) << endl;
    cout << obj->getRear() << endl;
    cout << obj->isFull() << endl;
    cout << obj->deleteLast() << endl;
    cout << obj->insertFront(4) << endl;
    cout << obj->getFront() << endl;
    delete obj;
    return 0;
}
