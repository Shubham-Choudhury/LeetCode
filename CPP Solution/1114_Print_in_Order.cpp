// Link: https://leetcode.com/problems/print-in-order/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class Foo {
private:
    bool firstDone, secondDone;
    mutex m;
    condition_variable cv1, cv2;
public:
    Foo() {
        firstDone = false;
        secondDone = false;
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstDone = true;
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lk(m);
        cv1.wait(lk, [this]{return firstDone;});
        lk.unlock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondDone = true;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lk(m);
        cv2.wait(lk, [this]{return secondDone;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

int main()
{
    Foo foo;
    thread t1(&Foo::first, &foo, [](){cout << "first" << endl;});
    thread t2(&Foo::second, &foo, [](){cout << "second" << endl;});
    thread t3(&Foo::third, &foo, [](){cout << "third" << endl;});
    t1.join();
    t2.join();
    t3.join();
    return 0;
}