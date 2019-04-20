#include <iostream>
using namespace std;
template<typename T> class Queue {
    private:
        T queueArray[NMAX];
        int head, tail, size;
    public:
        void enqueue(T x) {
            if (size == NMAX) {
               // fprintf(stderr, "Error 101 - The queue is full!\n");
                return;
            }
            queueArray[tail] = x;
            tail = (tail + 1) % NMAX;
            size++;
        }

        T dequeue() {
            if (isEmpty()) {
                //fprintf(stderr, "Error 102 - The queue is empty!\n");
                T x;
                return x;
            }
            T x = queueArray[head];
            head = (head + 1) % NMAX;
            size--;
            return x;
}
T peek() {
            if (isEmpty()) {
                //fprintf(stderr, "Error 103 - The queue is empty!\n");
                T x;
                return x;
            }
            return queueArray[head];
        }

        int isEmpty() {
            return (size == 0);
        }

    Queue() {
        head = tail = size = 0;
    }
};


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
