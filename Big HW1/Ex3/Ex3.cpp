/*
Hang Alexandru
1211EB - Faculty of Engineering In Foreign Languages (FILS-UPB)
Big Homework 1
Data Structures And Algorithms

EX3: Priority Queue
*/

#include <iostream>
#include "AdvancedStack.h"
#include <math.h>
#define I_MAX 4
#define J_MAX 5

using namespace std;

class room{
public:
    int name;
    double distance;
};

double getDistance(int x, int y){
    return sqrt(pow(x,2)+pow(y,2));
}

#include "PriorityQueue.h"

int main(){


    PriorityQueue FILS_rooms;
    int building[I_MAX][J_MAX] = {{0, 104,  0,   105,   1},
                                {0,   0,  0,   1,   0},
                                {1,   0,  1,  101, 102},
                                {0,   0,  0,   0,   103}} ;

    for(int i=0;i<I_MAX;i++)
        for(int j=0;j<J_MAX;j++){
            if(building[i][j]!=0 && building[i][j]!=1){
                    double dist=getDistance(i,j);
                    FILS_rooms.enQueue(building[i][j],dist);
                   // cout<<building[i][j];
            }

        }
        /*
    FILS_rooms.enQueue(201,getDistance(5,8));
    FILS_rooms.enQueue(100,getDistance(1,2));
*/
    while(FILS_rooms.isEmpty()!=1)
        cout<<FILS_rooms.deQueue()<<endl;

    return 0;
};

