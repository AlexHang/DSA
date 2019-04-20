#define NMAX 5
#include <stdio.h>
 class Queue {
    private:
        Message queueArray[NMAX];
        int head, tail, size;
    public:
        void enqueue(Message x) {
            if (size == NMAX) {
                fprintf(stderr, "Error 101 - The queue is full!\n");
                return;
            }
            queueArray[tail] = x;
            tail = (tail + 1) % NMAX;
            size++;
        }

        Message dequeue() {
            if (isEmpty()) {
                fprintf(stderr, "Error 102 - The queue is empty!\n");

                return Message();
            }
            Message x = queueArray[head];
            head = (head + 1) % NMAX;
            size--;
            return x;
}
        Message peek() {
            if (isEmpty()) {
                fprintf(stderr, "Error 103 - The queue is empty!\n");
                Message x;
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
