#include <iostream>
#include <stdlib.h>
#include "linkedlist.h"
using namespace std;
int counter=0;

struct Student{
    int Id;
    int ProjectId;
};

int ProjectMatrix[1024][1024];
int noStudents=3;
int noProjects=2;
int projects[100]={1,2};
Student posibilitati[100];
int nrPosibilitati=0;


void permutations(string str, int i, int n)
{

    // base condition
    if (i == n - 1)
    {
       // cout << str << endl;
       for(int j=0;j<noStudents;j++)
            ProjectMatrix[counter][j]=(int)str[j]-48;

        counter++;
        return;
    }

    // process each character of the remaining string
    for (int j = i; j < n; j++)
    {
        // swap character at index i with current character
        swap(str[i], str[j]);        // STL swap() used

        // recurse for string [i+1, n-1]
        permutations(str, i + 1, n);

        // backtrack (restore the string to its original state)
        swap(str[i], str[j]);
    }
}

void showProjects(){
    int aux=0,q=0;
    cout<<counter<<endl;
    for(int i=0;i<counter/noProjects;i++){

        for(int j=0;j<noStudents;j++){
           // cout<<aux%noProjects+1<<":"<<ProjectMatrix[i][j]<<"  ";
            aux++;
            posibilitati[nrPosibilitati].ProjectId=ProjectMatrix[i][j];
            posibilitati[nrPosibilitati].Id=aux%noProjects+1;
            nrPosibilitati++;
        }

       // cout<<endl;
    }

    for(int i=0;i<counter/noProjects;i++){

        for(int j=0;j<noStudents;j++){
          //  cout<<(noProjects-(aux%noProjects))%noProjects+1<<":"<<ProjectMatrix[i][j]<<"  ";
            aux++;
            posibilitati[nrPosibilitati].ProjectId=ProjectMatrix[i][j];
            posibilitati[nrPosibilitati].Id=(noProjects-(aux%noProjects))%noProjects+1;
            nrPosibilitati++;

        }

       // cout<<endl;
    }

}


void test(){
    for(int i=0;i<nrPosibilitati;i=i+3){
        cout<<posibilitati[i].Id<<":"<<posibilitati[i].ProjectId<<" ";
        cout<<posibilitati[i+1].Id<<":"<<posibilitati[i+1].ProjectId<<" ";
        cout<<posibilitati[i+2].Id<<":"<<posibilitati[i+2].ProjectId<<endl;
    }

}
// Find all Permutations of a string
int main()
{
    string str = "123";
    permutations(str, 0, noStudents);
    showProjects();

    test();
    return 0;
}
