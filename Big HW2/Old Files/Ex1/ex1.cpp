#include <iostream>
#include "linkedlist.h"
using namespace std;
int Students[]={1,2,3};
int Projects[]={1,2};
//int noStudents=7;
//int noProjects=3;


int projectAssign[100][100];

void StudentsForProject(int noStudents,int noProjects, int maxStudents){
 //int maxStudents=noStudents-noProjects;
    for(int i=0;i<=maxStudents;i++){
        projectAssign[0][i]=Students[i];
    }
    int j=1;
    for(int i=maxStudents+1;i<noStudents;i++){
        projectAssign[j][0]=Students[i];
        j++;
    }
    for(int i=0;i<noProjects;i++){
            cout<<"project "<<i<<": ";
        for(int j=0;j<noStudents;j++)
        if(projectAssign[i][j]!=0)
            cout<<projectAssign[i][j]<<" ";
        cout<<endl;
    }

}

int main(){


    for(int i=1;i<=2;i++)
        StudentsForProject(3,2,i);


    return 0;
}
