
#include "Stack.h"

template <typename T>class LargeStack{
 private:
    Stack<T> Smain,Saux;

 public:
    void Push(T x){
        Smain.push(x);
    }
    T Pop(){
        return Smain.pop();
    }

    T Peek(){
        return Smain.peek();
    }

    void Swap(int i, int j){
        // consider i<j
        T aux1,aux2;
        while(Smain.getSize()>j){
             Saux.push(Smain.pop());
        }
        aux1=Smain.peek();
        while(Smain.getSize()>i){
             Saux.push(Smain.pop());
        }
        aux2=Smain.peek();
        Saux.push(Smain.pop());
        Smain.push(aux1);
        Saux.pop();
        while(Smain.getSize()<j){
            Smain.push(Saux.pop());
        }
        Smain.push(aux2);
        while(Saux.isEmpty()!=1){
            Smain.push(Saux.pop());

        }
    }

    int isEmpty(){
        return Smain.isEmpty();
    }


};
