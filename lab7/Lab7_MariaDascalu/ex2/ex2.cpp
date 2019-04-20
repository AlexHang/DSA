#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
// http://www.cplusplus.com/reference/queue/queue/

template<typename TnodeInfo, typename TedgeInfo>
class Graph {
    public:
        int N;
        char **A;
        TnodeInfo *nodeInfo;
        TedgeInfo **edgeInfo;

        Graph(int numNodes) {
            int i, j;

            N = numNodes;

            // allocate the adjacency matrix
            A = new char*[N];
            for (i = 0; i < N; i++)
                A[i] = new char[N];
			for (i = 0; i < N; i++)
                for (j = 0; j < N; j++) A[i][j] = 0;

            // allocate the array with node information
            nodeInfo = new TnodeInfo[N];

            // allocate the matrix of edge information
            edgeInfo = new TedgeInfo*[N];
            for (i = 0; i < N; i++)
                edgeInfo[i] = new TedgeInfo[N];
        }

        void setNodeInfo(int i, TnodeInfo info) {
            nodeInfo[i] = info;
        }

        TnodeInfo getNodeInfo(int i) {
            return nodeInfo[i];
        }

        void addEdge(int i, int j) {
            A[i][j] = A[j][i] = 1;
        }
        void removeEdge(int i, int j) {
            A[i][j] = A[j][i] = 0; }

        void setEdgeInfo(int i, int j, TedgeInfo info) {
            edgeInfo[i][j] = edgeInfo[j][i] = info; }

        TedgeInfo getEdgeInfo(int i, int j) {
            return edgeInfo[i][j]; }

        ~Graph() {
            int i;
            for (i = 0; i < N; i++) {
                delete A[i];
                delete edgeInfo[i];
            }
            delete A;
            delete edgeInfo;
            delete nodeInfo;
        }
};
Graph<int, int> g(12);
char* visited;

void dfs(int x,int order,int maxorder) {
    int y;
    printf("%d\n", x);
    visited[x] = 1;

    for (y = 0; y < g.N; y++)
        if (g.A[x][y] && !visited[y] && order<=maxorder)
            dfs(y,order+1,maxorder);
}
void bfs(int S) {
    std::queue<int> Q;
    int x, y;

    Q.push(S);
    visited[S] = 1;

    while (!Q.empty()) {
        x = Q.front();
		Q.pop();
        printf("%d\n", x);
        for (y = 0; y < g.N; y++)
            if (g.A[x][y] && !visited[y]) {
                visited[y] = 1;
               Q.push(y);
            }
    }
}

int isBipartite(int s){
    int colorArr[12];
    for(int i=0;i<12;i++)
        colorArr[i]=-1;
    colorArr[s]=1;
    queue<int>q;
    q.push(s);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(g.A[u][u]==1) return 0;
        for(int v=0;v<12;v++){
            if(g.A[u][v] && colorArr[v]==-1){
                colorArr[v]=1-colorArr[u];
                q.push(v);
            }else if(g.A[u][v] && colorArr[v]==colorArr[u])
            return 0;

        }
    }
    return 1;
}


int main() {
    int i;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(7, 5);
    g.addEdge(2, 4);
    g.addEdge(5, 8);
    g.addEdge(7, 9);
    g.addEdge(4, 3);
    g.addEdge(8, 9);
    g.addEdge(4, 7);


    visited = new char[g.N];
    for (i = 0; i < g.N; i++)
        visited[i] = 0;


    if(isBipartite(1)==1)cout<<"yes";
        else cout<<"no";




   return 0;
}


