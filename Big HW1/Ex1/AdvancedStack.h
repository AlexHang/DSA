#include <iostream>
#include "Stack.h"
using namespace std;
class AdvancedStack{
private:
    Stack<double> stk;
    Stack<double>aux;
    double mini;
    double maxi;
public:
    AdvancedStack(){};

    void push(double t){
        if(stk.isEmpty()){
            mini=t;
            maxi=t;
        }else{
            if(t>=maxi)
                maxi=t;
            if(t<=mini)
                mini=t;
        }
        stk.push(t);
    }

    double peek(){
        return stk.peek();
    }

    int isEmpty(){
        return stk.isEmpty();
    }

    double pop(){
        if(stk.peek()>=maxi){
            stk.pop();
            maxi=stk.peek();
            while(stk.isEmpty()!=1){
                if(stk.peek()>maxi)
                    maxi=stk.peek();
                aux.push(stk.peek());
                stk.pop();
            }
            while(aux.isEmpty()!=1){
                stk.push(aux.peek());
                aux.pop();
            }
        }else{
            if(stk.peek()<=mini){
                stk.pop();
                mini=stk.peek();
                while(stk.isEmpty()!=1){
                    if(stk.peek()<mini)
                        mini=stk.peek();
                    aux.push(stk.peek());
                    stk.pop();
                }
                while(aux.isEmpty()!=1){
                    stk.push(aux.peek());
                    aux.pop();
                }
            }else stk.pop();
        }
    }

    double getMax(){
        return maxi;
    }
    double getMin(){
        return mini;
    }
};
