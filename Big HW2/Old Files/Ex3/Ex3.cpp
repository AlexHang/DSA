#include<iostream>
#include <list>
#include <stack>
#include <cstring>
#include <fstream>
using namespace std;
int letters[26];

ifstream fin("index.in");
ofstream fout("index.out");


class Graph{
    int V;


    list<int> *adj;


    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);


    void addEdge(int v, int w);


    void topologicalSort();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack){

    visited[v] = true;


    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    Stack.push(v);
}

void Graph::topologicalSort(){
    stack<int> Stack;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false){
        if(letters[Stack.top()]!=0){
            fout << (char) ('a' + Stack.top());
            cout<<   (char) ('a' + Stack.top());
        }

        Stack.pop();
    }
}

int min(int x, int y){
    return (x < y)? x : y;
}

void printOrder(string words[], int n){
    Graph g(26);
    for (int i = 0; i < n-1; i++){
        string word1 = words[i], word2 = words[i+1];
        for (int j = 0; j < min(word1.length(), word2.length()); j++)
        {

            if (word1[j] != word2[j])
            {
                g.addEdge(word1[j]-'a', word2[j]-'a');
                letters[word1[j]-'a']=1;
                letters[word2[j]-'a']=1;
                break;
            }
        }
    }


    g.topologicalSort();
}


int main(){

    string words[100];

    int counter=0;
    while(fin>>words[counter++]){
        if(words[counter-1]=="."){
             counter--;
             break;
        }

    }

    for(int i=0;i<26;i++)
        letters[i]=0;



    printOrder(words, counter);
    return 0;
}
