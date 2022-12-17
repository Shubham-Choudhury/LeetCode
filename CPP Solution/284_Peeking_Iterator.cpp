// Link: https://leetcode.com/problems/peeking-iterator/

#include <iostream>
#include <vector>
using namespace std;

class Iterator
{
    struct Data;
    Data *data;

public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator
{
    int nextVal;
    bool hasVal;

public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        hasVal = Iterator::hasNext();
        if (hasVal)
        {
            nextVal = Iterator::next();
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        return nextVal;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        int val = nextVal;
        hasVal = Iterator::hasNext();
        if (hasVal)
        {
            nextVal = Iterator::next();
        }
        return val;
    }

    bool hasNext() const
    {
        return hasVal;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    PeekingIterator iter(nums);
    cout << iter.next() << " ";
    cout << iter.peek() << " ";
    cout << iter.next() << " ";
    cout << iter.next() << " ";
    cout << iter.hasNext() << " ";
    return 0;
}