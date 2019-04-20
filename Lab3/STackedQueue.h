#include <iostream>
#include "Stack.h"

using namespace std;

template <typename T> class StackedQueue{

private:
    Stack<T> s1, s2;
public:
    void enQueue(T x)
    {

        while (!s1.isEmpty()) {
            s2.push(s1.peek());
            s1.pop();
        }

        s1.push(x);

        while (!s2.isEmpty()) {
            s1.push(s2.peek());
            s2.pop();
        }
    }


    int deQueue()
    {

        if (s1.isEmpty()) {
            cout << "Q is Empty";
            return -999999;
        }

        int x = s1.peek();
        s1.pop();
        return x;
    }

};
