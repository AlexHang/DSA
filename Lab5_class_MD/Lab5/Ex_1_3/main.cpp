#include <iostream>

using namespace std;
void display(int *arr){
for(int i=0; i<=5; i++)
    cout<<*(arr+i)<<" ";
}
 void rev(int *arr){
    for(int i=5; i>=0; i--){
       cout<<*(arr+i) <<" ";
    }
 }

 void reverseArray(int a[])
 {
     int *p = a;
     for(int i=0; i<3; i++)
        swap(*(p + i), *(p + 5 - i));
 }

int main()
{
    int arr[6];
    int*a=arr;
    for(int i=0;i<=5;i++)
    {
        //cin>>arr[i];
        cin>>*(a+i);
    }
    cout<<"Ex1"<<endl;
    display(arr);
    cout<<"Ex2"<<endl;
    rev(arr);
    cout<<"Ex3"<<endl;
    reverseArray(a);
    display(a);
    return 0;
}
