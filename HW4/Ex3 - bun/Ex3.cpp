#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
    int n;
    Stack<int> s;
    int aux;
    cout << "Enter n:";
    cin>> n;
    cout << endl;
    while(n!=0)
    {
        s.push(n%2);
        n = n/2;
    }
    cout<<"Binary number is: ";

    while(s.isEmpty()!=1)
    {
        aux = s.peek();
        s.pop();
        cout << aux ;
    }
    cout << endl;

    return 0;
}
