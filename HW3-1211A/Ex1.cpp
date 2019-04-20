#include <iostream>
#include "LargeStack.h"
using namespace std;
int main(){

    LargeStack<int> s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.Push(6);
    s.Push(7);

    s.Swap(2,5);
    while(s.isEmpty()!=1){
        cout<<s.Peek()<<endl;
        s.Pop();
    }
}
