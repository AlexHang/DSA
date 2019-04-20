#include <stdio.h>
#include <stdlib.h>



float average(float f1, float f2){
    return (f1+f2)/2;
}
float minimum(float f1, float f2, float f3){
    if(f1<f2 && f1<f3)
        return f1;
    if(f2<f3 && f2<f1)
        return f2;
    if(f3<f1 && f3<f2)
        return f3;
}

int digitsum(int nr){
    int sum=0;
    while(nr!=0){
        sum+=nr%10;
        nr/=10;
    }
    return sum;
}

float intervaldigitsum(int a, int b){
    float sum=0;
    int i;
    for(i=a;i<=b;i++){
        sum+=digitsum(i);
    }
    return sum;
}
int palindrom(int nr){
    int aux=0,cp=0;
    cp=nr;
    while(cp!=0){
        aux=aux*10+cp%10;
        cp/=10;
    }
    if(aux==nr)
        return 1;
    else return 0;
}

int main()
{
    /*
    printf("Hello world!\n");
    int number=10;
    char ch='a';
    char str[]="Hello, World! ";
    printf("integer  %d \n",number);
    printf("A character: %c \n",ch);
    printf("A string: %s",str);

    printf("some chars \n %8c \n",getchar());
    printf("some chars \n %8s \n","Hello world !");
    printf("Some integers \n %8d \n",123);

    float a,b;
    scanf("%f",&a);
    scanf("%f",&b);
    printf("%.2f",average(a, b));*/

    printf("the minimum is %.2f \n", minimum(2.0,5,7.3));
    printf("the sum of digits between 5 and 11 is %.0f \n",intervaldigitsum(5,11));
    if(palindrom(1223221)==1)
        printf("yes");
        else printf("no");

    return 0;
}
