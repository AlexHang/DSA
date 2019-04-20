#include <iostream>
using namespace std;

struct date{
    unsigned int day;
    unsigned int month;
    unsigned int year;
    char name_day[4];
    char name_month[4];
    bool checkDate(){
        bool aux=true;
        if(this->year<1000 && this->year>9999)
            aux=false;
        if(this->month>11)
            aux=false;
        switch(this->month){
            case 0:
               if(this->day>31)
                    aux=false;
                break;

            case 1:
                   if(this->day>28)
                    aux=false;
                    break;
            default:
                    if(this->month%2==0){
                        if(this->day>30)
                            aux=false;
                    }
                    else if(this->day>31)
                        aux=false;
                        break;
        }
        return aux;

    };
    date getTomorrow(){
        date aux;
        if(this->month%2==0 && this->day==31){
                aux.day==1;
                aux.month=this->month++;
        } else if(this->month%2==1 && this->day==30){
                aux.day==1;
                aux.month=this->month++;
        }
        else if(this->month==1 && this->day==28){
            aux.day=1;
            aux.month=2;
        }
        else {
            aux.day=this->day+1;
            aux.month=this->month;
        }
        aux.year=this->year;

        return aux;


    }

};


/*


void swap(int &a,int &b){
    int aux;
    aux=a;
    a=b;
    b=aux;
}
void SortArray(int v[]){
    int i,j;
    for(i=0;i<7-1;i++){
        for(j=i;j<7;j++)
            if(v[i]>v[j])
                swap(v[i],v[j]);
    }
}
*/
int main(){
    date d1,tomorrow;
    d1.day=23;
    d1.month=1;
    d1.year=2019;

    if(d1.checkDate()==0)
        cout<<"the date is NOT correct";
    else cout<<"the date is correct";

    tomorrow=d1.getTomorrow();
    cout<<"tomorrow is:"<<tomorrow.day<<"/"<<tomorrow.month<<"/"<<tomorrow.year;

    return 0;
}
