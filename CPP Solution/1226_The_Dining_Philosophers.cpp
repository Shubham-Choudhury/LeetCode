// Link: https://leetcode.com/problems/the-dining-philosophers/

#include <bits/stdc++.h>
using namespace std;

class DiningPhilosophers
{
    mutex forks[5];
    mutex eat;

public:
    DiningPhilosophers()
    {
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork)
    {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        if (philosopher % 2 == 0)
        {
            forks[left].lock();
            forks[right].lock();
        }
        else
        {
            forks[right].lock();
            forks[left].lock();
        }
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        forks[left].unlock();
        forks[right].unlock();
    }
};

void main(){
    DiningPhilosophers s;
    s.wantsToEat(0, [](){}, [](){}, [](){}, [](){}, [](){});
}