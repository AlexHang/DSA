#include <iostream>
#include <stdlib.h>
#include "list.h"
using namespace std;

void getDuplicates(LinkedList<int> arr){
    LinkedList<int> duplicates;
    LinkedList<int> goodList;
    Node<int>* el;
    Node<int>* el2;
    Node<int>* dup;

    el=arr.pfirst;
    el2 = el;
    int counter=0;

        while (el != NULL)
        {   counter=0;
           // cout<<endl<<el->info<<" ";
            el2 = el->next;
            while(el2!=NULL){
                /* If duplicate then delete it */
               // cout<<el2->info;
                if (el->info == el2->info)
                {   counter++;
                    //cout<<el2->info;
                    /* sequence of steps is important here */
                   // dup = el2->info;
                    //el2->next = el2->next->next;
                    duplicates.addLast(el2->info);
                    el2=el2->next;

                    //arr.removeLastOccurrence(el2->info);
                }else{
                    el2=el2->next;
                    }

            }
            if(counter==0) goodList.addFirst(el->info);

            el = el->next;
        }


    cout<<"List of duplicates: ";
    duplicates.printList();
    cout<<endl;
    cout<<"List without duplicates: ";
    goodList.printList();

}


int main(){

    LinkedList<int>myList;
    myList.addFirst(2);
    myList.addLast(2);
    myList.addLast(4);
    myList.addLast(2);
    myList.addLast(5);
    myList.addLast(4);
    myList.addLast(2);
    getDuplicates(myList);

}
