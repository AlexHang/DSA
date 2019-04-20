#include <iostream>
#include "complex.h"
using namespace std;

int main(){
    complex c1(2,5);
    c1.afisare();
    complex c2(3,1);
    c2.afisare();
    cout<<"the sum is: ";
    c1.adunare(c2);
    cout<<"the multiplication is: ";
    c1.inmultire(c2);
    return 0;
}
