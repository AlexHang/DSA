/*
Hang Alexandru
1211EB - Faculty of Engineering In Foreign Languages (FILS-UPB)
Big Homework 1
Data Structures And Algorithms

EX2: find a route in a matrix
*/

#include <iostream>
#include "Stack.h"
#include <string.h>
#include <stdlib.h>
#define I_MAX 4
#define J_MAX 5
using namespace std;

int building[I_MAX][J_MAX];

int CJbuilding[I_MAX][J_MAX] = {{0, 104,  0,   0,   1},
                                {0,   0,  0,   1,   0},
                                {1,   0,  1,  101, 102},
                                {0,   0,  0,   0,   0}} ;
 int ANbuilding[I_MAX][J_MAX] = {{0, 201,  202,   202,   1},
                                { 0,   0,   0,    0,   203},
                                { 0,   207,  206,  205, 204},
                                { 0,   0,  0,   0,   208}} ;

 int JAbuilding[I_MAX][J_MAX] = {{0, 0,  101,   102,   1},
                                {0,   0,  0,   1,   0},
                                {1,   0,  1,  105, 106},
                                {0,   0,  0,   0,   0}} ;

int visited[I_MAX][J_MAX] ={{0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0}} ;


int target=0;
int noSteps=0;

class Point{
public:
    int i;
    int j;
    Point(){};
    Point(int i, int j){
        this->i=i;
        this->j=j;
    };
};

Stack<Point>visitedPoints;


int wasVisited(int i, int j){
    return visited[i][j]==1;
}

int isDeadEnd(Point location){
    int counter=0;
    int i=location.i;
    int j=location.j;
    if(i>I_MAX-1) return 1;
    if(j>J_MAX-1) return 1;
    if(i<0) return 1;
    if(j<0) return 1;
    if(i==0) counter++;
    if(j==0) counter++;
    if(i==I_MAX-1) counter++;
    if(j==J_MAX-1) counter++;
    if(building[i+1][j]!=0 && building[i+1][j]!=target) counter++;
    if(building[i-1][j]!=0 && building[i-1][j]!=target) counter++;
    if(building[i][j+1]!=0 && building[i][j+1]!=target) counter++;
    if(building[i][j-1]!=0 && building[i][j-1]!=target) counter++;

   // return counter;

    if(counter>=4)
        return 1;
    else return 0;
}

void showSteps(){
   //
  while(!visitedPoints.isEmpty()){
        cout<<visitedPoints.peek().i<<" "<<visitedPoints.peek().j<<endl;
        if(visitedPoints.peek().i==0 && visitedPoints.peek().j==0)
            return;
        visitedPoints.pop();


    }
}

void findRoute(Point location, Point target){
    noSteps++;
    int i=location.i;
    int j=location.j;
    visited[i][j]=1;
    visitedPoints.push(location);
    if((location.i==target.i)&&(location.j==target.j))  {cout<<"Destination reached";  return;}
    else{

        //cout<<location.i<<" "<<location.j<<endl;

        if(isDeadEnd(Point(i,j))){
            visitedPoints.pop();
            findRoute(visitedPoints.peek(),target);
        }

        if(i+1==target.i && j==target.j ||
           i-1==target.i && j==target.j ||
           i==target.i && j+1==target.j ||
           i==target.i && j-1==target.j){
            cout<<"Destination reached"<<endl;
            cout<<target.i<<" "<<target.j<<endl;
            showSteps();
           }

        if(isDeadEnd(Point(i+1,j))!=1 && visited[i+1][j]!=1 && building[i+1][j]==0 ){
            findRoute(Point(i+1,j),target);
          //  visitedPoints.pop();
        }

        if(isDeadEnd(Point(i-1,j))!=1 && visited[i-1][j]!=1 && building[i-1][j]==0){
            findRoute(Point(i-1,j),target);
           // visitedPoints.pop();
        }

        if(isDeadEnd(Point(i,j+1))!=1 && visited[i][j+1]!=1 && building[i][j+1]==0){
            findRoute(Point(i,j+1),target);
           // visitedPoints.pop();
        }

        if(isDeadEnd(Point(i,j-1))!=1 && visited[i][j-1]!=1 && building[i][j-1]==0){
            findRoute(Point(i,j-1),target);
            //visitedPoints.pop();
        }


    }


}









int main(){

    Point x(0,0);
     Point final_destination(0,0);
    char destination[10],inputbuilding[10];
    cout<<"Introduceti Destinatia: ";
    cin>>destination;
    inputbuilding[0]=destination[0];
    inputbuilding[1]=destination[1];
    target = (destination[2]-48)*100+(destination[3]-48)*10+(destination[4]-48);
    //cout<<target;
    if(inputbuilding[0]=='c' && inputbuilding[1]=='j'){
            for(int i=0;i<I_MAX;i++)
                for(int j=0;j<J_MAX;j++)
                    building[i][j]=CJbuilding[i][j];

        for(int i=0;i<I_MAX;i++)
            for(int j=0;j<J_MAX;j++)
                if(building[i][j]==target){
                   final_destination.i=i;
                   final_destination.j=j;
                }
        noSteps=0;
        findRoute(Point(0,0),final_destination);
        }

    if(inputbuilding[0]=='a' && inputbuilding[1]=='n'){

        for(int i=0;i<I_MAX;i++)
                for(int j=0;j<J_MAX;j++)
                    building[i][j]=ANbuilding[i][j];

        for(int i=0;i<I_MAX;i++)
            for(int j=0;j<J_MAX;j++)
                if(building[i][j]==target){
                   final_destination.i=i;
                   final_destination.j=j;
                }
        noSteps=0;
        findRoute(Point(0,0),final_destination);
    }
    if(inputbuilding[0]=='j' && inputbuilding[1]=='a'){
        for(int i=0;i<I_MAX;i++)
                for(int j=0;j<J_MAX;j++)
                    building[i][j]=JAbuilding[i][j];

        for(int i=0;i<I_MAX;i++)
            for(int j=0;j<J_MAX;j++)
                if(building[i][j]==target){
                   final_destination.i=i;
                   final_destination.j=j;
                }
        noSteps=0;
        findRoute(Point(0,0),final_destination);


    }
    return 0;
}



/*
 Alexandru Hang 1211EB
*/
