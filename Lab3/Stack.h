#include <iostream>
#include "Queue.h"

template<typename T> class Stack{
    Queue<T> q1, q2;
    int curr_size;

    public:
    Stack()
    {
        curr_size = 0;
    }

    void push(int x)
    {
        curr_size++;
        q2.enqueue(x);
        while (!q1.isEmpty())
        {
            q2.enqueue(q1.peek());
            q1.dequeue();
        }
        Queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    T pop(){
        if (q1.isEmpty())
            return -9999;
        q1.dequeue();
         curr_size--;
        return q1.peek();

    }


    T peek()
    {
        if (q1.isEmpty())
            return -1;
        return q1.peek();
    }

    int isEmpty()
    {
        return curr_size==0;
    }
};
