#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;
void swap(double* a, double* b)
{
    double t = *a;
    *a = *b;
    *b = t;
}
struct element{
    Point p;
    double dist;
};
int getDistance(Point p){
    return sqrt(pow(p.getX(),2)+pow(p.getY(),2));
}

double partition (double arr[], int low, int high)
{
    double pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(double arr[], int low, int high)
{
    if (low < high)
    {

        double pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



int main(){
    Point p1(1,5);
    Point p2(5,3);
    Point p3(2,1);
    Point p4(5,7);
    Point p5(4,5);

    Point points[]={p1,p2,p3,p4,p5};
    double dist[]={getDistance(p1),getDistance(p2),getDistance(p3),getDistance(p4),getDistance(p5)};
    quickSort(dist,0,4);

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(dist[i]==getDistance(points[j])){
                cout<<points[j].getX()<<" "<<points[j].getY()<<endl;
                points[j]=Point(9999,99999);
            }
        }
    }

}
