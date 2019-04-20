#include <iostream>
#include "date.h"
using namespace std;
int main(){

    date d1(1,2,2019),
        tomorrow,
        yesterday;
    if(d1.checkDate()==0)
        cout<<"the date is NOT correct";
    else cout<<"the date is correct";
    cout<<endl;
    tomorrow=d1.getTomorrow();
    cout<<"tomorrow is:"<<tomorrow.day<<"/"<<tomorrow.month<<"/"<<tomorrow.year<<endl;
    yesterday=d1.getYesterday();
    cout<<"Yesterday was:"<<yesterday.day<<"/"<<yesterday.month<<"/"<<yesterday.year;


    return 0;
}
