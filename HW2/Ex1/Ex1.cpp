#include <iostream>
using namespace std;

struct Polynom{
    int coef[50];
    int max_exponent=1;
    void Print(){
        for(int i=1;i<=max_exponent;i++)
            if(coef[i]!=0)
                cout<<" "<<coef[i]<<"X^"<<i;
        cout<<endl;
    }
};

struct TMonom{
    int Coef;
    int Exponent;
};

TMonom TPolinom[50];

void readMonom(TMonom &t){
    cout<<"Coeficient:";
    cin>>t.Coef;
    cout<<"Exponent:";
    cin>>t.Exponent;
}
void printMonom(TMonom t){
    cout<<t.Coef<<"X^"<<t.Exponent<<" "<<endl;
}
Polynom Addition(TMonom a, TMonom b){
    int max_exponent;
    if(a.Exponent>b.Exponent)
        max_exponent=a.Exponent;
        else max_exponent=b.Exponent;
    Polynom P;
    P.max_exponent=max_exponent;
    for(int i=1;i<=max_exponent;i++){
        // aici o sa fac suma
        if(a.Exponent==b.Exponent && b.Exponent==i)
            P.coef[i]=a.Coef+b.Coef;
        else if(a.Exponent==i)
                P.coef[i]=a.Coef;
                else if(b.Exponent==i)
                        P.coef[i]=b.Coef;
                        else P.coef[i]=0;
    }
    return P;
};

TMonom multiplication(TMonom t1, TMonom t2){
    TMonom result;
    result.Exponent=t1.Exponent+t2.Exponent;
    result.Coef=t1.Coef*t2.Coef;
    return result;
};


int main(){

    TMonom t1,t2,t3;
    readMonom(t1);
    readMonom(t2);
    cout<<"t1 is:";
    printMonom(t1);
    cout<<"t2 is:";
    printMonom(t2);
    Polynom P = Addition(t1,t2);
    cout<<"The addition result is: ";
    P.Print();
    t3=multiplication(t1,t2);
    cout<<"The multiplication result is: ";
    printMonom(t3);
    return 0;
}
