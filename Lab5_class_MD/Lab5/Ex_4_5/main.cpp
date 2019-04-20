#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char getCounty(char *p){
    int ok = 0;
    while(*p){
        if(*p == ','){
            ok = 1;
        }

        if(ok == 1 && (*p >= 'A' && *p <= 'Z')){
            cout << *p;
        }

        p++;
    }
}

char *replace_comma(char *p){
    char *aux;
    aux=strtok(p,",");
    while(aux!=NULL){
        cout<<aux<<" ";
        aux=strtok(NULL,",");
    }
}
int main()
{
    char s[] = "Slatina, OT";
    char *q = s;
    getCounty(q);

    char p[]="College,Of,London,UK,Europe";
    replace_comma(p);
    return 0;
}
