#include <iostream>
#include "Stack.h"
#include <string.h>
using namespace std;

int main(){
    char my_str[]="a santa at nasa";
    char new_str[100];
    int aux=0,isPalindrome=1;
    Stack<char> myStack;

    //remove white spaces from String
    for(int i=0;i<strlen(my_str);i++){
        if(my_str[i]!=' ')
            new_str[aux++]=my_str[i];
    }
    strlwr(new_str);//make everything lower case

    for(int i=aux-1;i>=0;i--){
        myStack.push(new_str[i]);
    }

    while(myStack.isEmpty()==0){
        if(myStack.peek()!=new_str[--aux])
            isPalindrome=0;
       // cout<<myStack.peek()<<" "<<new_str[aux]<<endl;
        myStack.pop();
    }

    if(isPalindrome==1){
        cout<<"yes, it is palindrome";
    }else{
        cout<<"no";
    }



}
