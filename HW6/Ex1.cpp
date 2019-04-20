#include <iostream>
#include <stdlib.h>
#include "list.h"

using namespace std;

int secondSmallest(LinkedList<int> arr){
    int first,second;
    first=arr.pfirst->info;
    second=arr.pfirst->next->info;
    if(second<first){
        int aux=first;
        first=second;
        second=first;
    }
    Node <int>* currentNode=arr.pfirst;
    while(currentNode!=NULL){
        if(currentNode->info<first){
            second=first;
            first=currentNode->info;
        }

        else if(currentNode->info<second){
            second=currentNode->info;
        }


        currentNode=currentNode->next;
    }
    return second;
}

int main(){
    LinkedList<int> myList;
    myList.addFirst(5);
    myList.addLast(3);
    myList.addLast(6);
    myList.addLast(2);
    myList.addLast(8);
    myList.addLast(4);
    myList.addLast(1);
    cout<<secondSmallest(myList);
}
