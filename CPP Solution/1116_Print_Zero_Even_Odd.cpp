// Link: https://leetcode.com/problems/print-zero-even-odd/

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class ZeroEvenOdd
{
private:
    int n;
    mutex m;
    condition_variable cv;
    int state = 0;

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i++)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this] { return state == 0; });
            printNumber(0);
            state = i % 2 == 0 ? 2 : 1;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this] { return state == 2; });
            printNumber(i);
            state = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this] { return state == 1; });
            printNumber(i);
            state = 0;
            cv.notify_all();
        }
    }
};

int main()
{
    ZeroEvenOdd s(5);
    thread t1(&ZeroEvenOdd::zero, &s, [](int x) { cout << x; });
    thread t2(&ZeroEvenOdd::even, &s, [](int x) { cout << x; });
    thread t3(&ZeroEvenOdd::odd, &s, [](int x) { cout << x; });
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
