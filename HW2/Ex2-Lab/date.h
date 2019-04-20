#include <iostream>
using namespace std;
class date{

public:
    unsigned int day;
    unsigned int month;
    unsigned int year;
    char name_day[4];
    char name_month[4];
    date(){};
    date(unsigned int day, unsigned int month,unsigned int year){
        this->day=day;
        this->month=month;
        this->year=year;
    }
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
    date getYesterday(){
        date aux(this->day,this->month,this->year);
        if(this->day==1){
            if(this->month==2){
                aux.day=28;
                aux.month=2;
            }else{
                if(this->month%2==0){
                    aux.day=30;
                    aux.month--;
                }
                else{
                    aux.day=31;
                    aux.month--;
                }

            }
        }
        else{
            aux.day--;
        }
        return aux;
    }

};
