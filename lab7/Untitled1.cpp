#include <iostream>
#include "list.h"
using namespace std;
int main(){

    LinkedList<int> arr;
    arr.addFirst(1);
    arr.addLast(7);
    arr.addLast(8);
    arr.addLast(0);
    arr.addLast(1);
    arr.addLast(9);
    arr.addLast(7);
    arr.addLast(8);
    arr.addLast(3);
    arr.addLast(4);
    arr.addLast(2);



    Node<int>* el;
    el=arr.pfirst;
    int counter=0;
    while(el!=NULL){
        el=el->next;
        counter++;
        if(counter%3==0)
            arr.removeFirstOccurrence(el->prev->info);
       // arr.removeFirstOccurrence(el->next->info);

    }

    arr.printList();


}
