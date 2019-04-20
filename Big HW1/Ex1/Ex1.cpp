/*
Hang Alexandru
1211EB - Faculty of Engineering In Foreign Languages (FILS-UPB)
Big Homework 1
Data Structures And Algorithms

EX1: Advanced Stack
*/

#include <iostream>
#include "AdvancedStack.h"
using namespace std;
int main(){
    AdvancedStack myStk;
    myStk.push(4);
    myStk.push(5);
    myStk.push(3);
    myStk.push(7);
    myStk.push(3);
    myStk.push(22);
    myStk.push(4);
    myStk.push(2);

    while(myStk.isEmpty()!=1){
        cout<<"Top: "<<myStk.peek()<<" Maximum: "<<myStk.getMax()<<" Minimum: "<<myStk.getMin()<<endl;
        myStk.pop();
    }
}
