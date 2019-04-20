#include <iostream>
#include <string.h>
using namespace std;

class BankAccount{
private:
    string Name;
    string IBAN;
    string Adress;
    int sum=0;
public:
    BankAccount(){};
    BankAccount(string Name,string IBAN,string Adress){
        this->Name=Name;
        this->IBAN=IBAN;
        this->Adress=Adress;
    }


    void deposit(int s){
        this->sum+=s;
        cout<<"Successfully added "<<s<<" dollars"<<endl;
    }
    void withdraw(int s){
        if(s<this->sum){
            sum-=s;
            cout<<"Successfully withdraw "<<s<<" dollars"<<endl;
        }

        else cout<<"Error, not enough money"<<endl;
    }
    void displayAmmount(){
        cout<<"You currently have: "<<this->sum<<" dollars"<<endl;
    }
    void displayOwner(){
        cout<<"The owner of the account is:"<<this->Name<<endl;
    }

};


int main(){

    BankAccount MyAcc = BankAccount("Alex Hang","1123456763876","Bucharest");
    MyAcc.deposit(500);
    MyAcc.deposit(300);
    MyAcc.withdraw(1500);
    MyAcc.withdraw(200);
    MyAcc.displayAmmount();
    MyAcc.displayOwner();
    return 0;
}
