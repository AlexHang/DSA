/*

Big Homework 2

Exercise 2

Diana Scurtu & Alex Hang

*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;

int M;
ifstream fin("streets.in");


class Graph{
public:
    int Matrix[44][44];
    Graph(){

        for(int i=0;i<M;i++)
            for(int j=0;j<M;j++)
                Matrix[i][j]=0;
    };
    void addEdge(int i, int j){
        Matrix[i][j]=1;
        Matrix[j][i]=1;
    }
    void printGraph(){
        for(int i=0;i<M;i++){
             for(int j=0;j<M;j++)
                 cout<<Matrix[i][j]<<" ";
            cout<<endl;
        }

    }
};

Graph g;

void printSolution(int path[]);

int isSafe(int v, int graph[44][44], int path[], int pos)
{
    if (graph [ path[pos-1] ][ v ] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}


int Hamilton(int graph[44][44], int path[], int pos)
{

    if (pos == M)
    {

        if ( graph[ path[pos-1] ][ path[0] ] == 1 )
           return true;
        else
          return false;
    }
    for (int v = 1; v < M; v++)
    {
        /* Check if this vertex can be added to Hamiltonian Cycle */
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            if (Hamilton (graph, path, pos+1) == true)
                return true;


            path[pos] = -1;
        }
    }


    return false;
}

int hamCycle(int graph[44][44])
{
    int *path = new int[M];
    for (int i = 0; i < M; i++)
        path[i] = -1;

    path[0] = 0;
    if ( Hamilton(graph, path, 1) == false )
    {
        printf("\n Johnny has no route");
        return false;
    }

    printSolution(path);
    return true;
}


void printSolution(int path[])
{
    printf ("Johnny's route \n");
    for (int i = 0; i < M; i++)
        printf(" %d ", path[i]);


    printf(" %d ", path[0]);
    printf("\n");
}

int main()
{
    int N;
    fin>>M;
    fin>>N;
    for(int i=0;i<N;i++){
        int node1,node2;
        fin>>node1;
        fin>>node2;
        g.addEdge(node1,node2);
       // cout<<node1<<" "<<node2<<endl;
    }

   /* g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,4);
    g.addEdge(4,3);
    g.addEdge(3,0);*/


    hamCycle(g.Matrix);



    return 0;
}


/*

Big Homework 2

Exercise 2

Diana Scurtu & Alex Hang

*/
