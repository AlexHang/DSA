#include "linkedlist.h"
#include <iostream>
using namespace std;
int main(){
    LinkedList<int> myList;
    myList.addLast(1);
    myList.addLast(5);
    myList.addLast(10);
    myList.addLast(22);
    int sum=0;
    list_elem <int>* myElement=myList.pfirst;
    while(myElement!=NULL){

        sum+=myElement->info;
        myElement=myElement->next;
    }
    cout<<sum;
    return 0;
}
