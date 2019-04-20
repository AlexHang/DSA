#include "linkedlist.h"
#include <iostream>
template <typename T>class QueueWithList{

private:
    LinkedList<T> myList;
public:
    QueueWithList(){};
    void enQueue(T x){
        myList.addLast(x);
    }
    T deQueue(){
        T aux = myList.pfirst->info;
        myList.removeFirst();
        return aux;

    }

    T peek(){
        return myList.pfirst.info;
    }

    int isEmpty(){
        return myList.isEmpty();
    }

};

int main(){
    QueueWithList<int> q1;
    q1.enQueue(5);
    q1.enQueue(3);
    q1.enQueue(2);

    cout<<q1.deQueue()<<endl;
    cout<<q1.deQueue()<<endl;
    cout<<q1.deQueue()<<endl;
}
