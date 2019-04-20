#include <stdio.h>
#include <stdlib.h>

int isPrime(int nr){
    int i,aux=0;
    for(i=2;i<=nr/2;i++){
        if(nr%i==0)
            aux++;
    }
    if(aux==0)
        return 1;
    else return 0;
}

void primeNumbers(int n){
    int i=0,counter=0;
    while(counter<n){
        i++;
        if(isPrime(i)==1){
            printf(" %d ",i);
            counter++;
        }

    }
}

double factorial(int nr){
    int i;
    double fact=1;
    for(i=1;i<=nr;i++)
        fact=fact*i;
    return fact;

}

void relativelyPrime(int n1, int n2){
    int aux=0;
    while(n1!=n2){
        if(n2>n1)
            n2-=n1;
        else n1-=n2;
    }
    if(n1==1) printf("\n Yes, they are prime");
   else printf("\n No, they are not prime");
}

int main()
{

   // printf("Hello world!\n");
   int aux1,aux2,aux3,aux4;
   printf("How many prime numbers should I display ? \n");
   scanf("%d",&aux1);
   //printf("\n");
   primeNumbers(aux1);
   printf("\n Enter the number to find the factorial \n");
   scanf("%d",&aux2);
  // printf("%d ! = %.0f \n",aux2,factorial(5));
   printf("%d ! = %.0f \n",aux2,factorial(aux2));
   printf("Enter the 2 numbers to find if they are prime: \n");
   scanf("%d %d",&aux3,&aux4);
   relativelyPrime(aux3,aux4);

    return 0;
}
