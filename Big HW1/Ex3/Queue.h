#define NMAX 10
#include <stdio.h>
#include <stdlib.h>
 class Queue {
    private:
        room queueArray[NMAX];
        int head, tail, size;
    public:
        void enqueue(room x) {
            if (size == NMAX) {
                fprintf(stderr, "Error 101 - The queue is full!\n");
                return;
            }
            queueArray[tail].name = x.name;
            queueArray[tail].distance = x.distance;
            tail = (tail + 1) % NMAX;
            size++;
        }

        room dequeue() {
            if (isEmpty()) {
                fprintf(stderr, "Error 102 - The queue is empty!\n");
                room x;
                return x;
            }
            room x = queueArray[head];
            head = (head + 1) % NMAX;
            size--;
            return x;
}
        room peek() {
            if (isEmpty()) {
                fprintf(stderr, "Error 103 - The queue is empty!\n");
                room x;
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

