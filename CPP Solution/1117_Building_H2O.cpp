// Link: https://leetcode.com/problems/building-h2o/

#include <bits/stdc++.h>
using namespace std;

class H2O
{
public:
    H2O()
    {
    }

    void hydrogen(function<void()> releaseHydrogen)
    {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this]
                { return state == 0 || state == 1; });
        releaseHydrogen();
        state = state == 0 ? 1 : 2;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen)
    {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this]
                { return state == 2; });
        releaseOxygen();
        state = 0;
        cv.notify_all();
    }

private:
    mutex m;
    condition_variable cv;
    int state = 0;
};

int main()
{
    H2O h2o;
    thread t1(&H2O::hydrogen, &h2o, []()
              { cout << "H"; });
    thread t2(&H2O::hydrogen, &h2o, []()
              { cout << "H"; });
    thread t3(&H2O::oxygen, &h2o, []()
              { cout << "O"; });
    thread t4(&H2O::hydrogen, &h2o, []()
              { cout << "H"; });
    thread t5(&H2O::hydrogen, &h2o, []()
              { cout << "H"; });
    thread t6(&H2O::oxygen, &h2o, []()
              { cout << "O"; });
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    return 0;
}
