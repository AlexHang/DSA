#include <iostream>
#include "minheap.h"
#include "maxheap.h"
using namespace std;



MaxHeap<int>maxH(100);
MinHeap<int>minH(100);

int arr[] = {8,7,8,5,3,5,8};
int n = sizeof(arr) / sizeof(int)-1;



bool isHeap(int arr[], int i, int n){
// If a leaf node
if (i > (n - 2)/2)
    return true;

// If an internal node and is greater than its children, and
// same is recursively true for the children
if (arr[i] >= arr[2*i + 1] && arr[i] >= arr[2*i + 2] &&
    isHeap(arr, 2*i + 1, n) && isHeap(arr, 2*i + 2, n))
    return true;

return false;
}


int getSecondBest(){


   // H[2 * l + 1]
   // H[2 * (l+1) ]
    int root=maxH.currentDim/2;

    while(2 * (root+1)<=maxH.currentDim){
        root = 2 * (root+1);
    }
    root=(root-1)/2;


   return maxH.H[2*root + 1];

}

void showHistory(){
    int lvl=1;
    int root=(maxH.currentDim-1)/2;
    //cout<<root;
    while(root<=maxH.currentDim){
        root = 2 * root;
        cout<<"Round: "<<lvl++<<" : "<<maxH.H[((root-1)/2)*2 -1]<<endl;
    }

}

void LoserTree(){
    for(int i=0;i<n;i++){
        minH.insertElement(arr[n-i]);
    }
    int root=(minH.currentDim-1)/2;
    //cout<<root;
    while(root<=minH.currentDim){
        root = 2 * root;
    }
    cout<<"Main Loser: "<<minH.peek()<<endl;
    cout<<"Main Winner"<<root<<endl;
}

int main(){








    isHeap(arr, 0, n)? cout<<"Yes": cout<<"No";
    cout<<endl;


    for(int i=0;i<n;i++){
        maxH.insertElement(arr[i]);
    }

    cout<<"Second best player is:"<<getSecondBest()<<endl;

showHistory();
cout<<endl;
LoserTree();
}
