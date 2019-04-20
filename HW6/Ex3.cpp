#include <iostream>
#include <stdlib.h>
#include "list.h"
using namespace std;

struct tuplet{
    int x;
    int y;
};

void orderList(LinkedList<tuplet> arr){

    Node<tuplet>* el;
    Node<tuplet>* el2;
    Node<tuplet>* aux;

    el=arr.pfirst;
    el2 = el;
    int counter=0;

        while (el != NULL)
        {   el2=el->next;
            while(el2!=NULL){

                    if(el2->info.y<el->info.y){
                        int auxx,auxy;
                        auxx=el2->info.x;
                        el2->info.x=el->info.x;
                        el->info.x=auxx;


                        auxy=el2->info.y;
                        el2->info.y=el->info.y;
                        el->info.y=auxy;
                    }

                    el2=el2->next;
            }
            el = el->next;
        }
        el=arr.pfirst;
        while (el != NULL){
            cout<<el->info.x<<" "<<el->info.y<<endl;
            el=el->next;
        }


}


int main(){
    LinkedList<tuplet> myList;
    tuplet t1,t2,t3,t4;
    t1.x=2;
    t1.y=5;

    t2.x=5;
    t2.y=1;

    t3.x=4;
    t3.y=3;

    t4.x=2;
    t4.y=7;



    myList.addLast(t1);
    myList.addLast(t2);
    myList.addLast(t3);
    myList.addLast(t4);
    orderList(myList);

}
