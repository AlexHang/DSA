#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
// http://www.cplusplus.com/reference/queue/queue/

int myUser;


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


void getAllFriends(int userId, int order, int maxOrder){
    if(order<=maxOrder){
        int counter=0;
    for(int i=0;i<12;i++){
        for(int j=0;j<i;j++)
            if((g.A[i][j]&&(i==userId || j==userId))  ){
                if(i==userId && j!=myUser){
                        cout<<"friend of order "<<order<<" is: "<<j<<endl;
                        getAllFriends(j,order+1,maxOrder);

                }
                if(j==userId && i!=myUser){
                    cout<<"friend of order "<<order<<" is: "<<i<<endl;
                    getAllFriends(i,order+1,maxOrder);
                }
                counter++;
            }


    }
   // cout<<"he has"<<counter<<" friends of order "<<order<<endl;
    }


}

int main() {
    int i;
    g.addEdge(0, 1);    g.addEdge(1, 3);
    g.addEdge(0, 3);    g.addEdge(5, 3);
    g.addEdge(3, 6);    g.addEdge(6, 10);
    g.addEdge(6, 11);    g.addEdge(10, 11);
    g.addEdge(6, 4);    g.addEdge(2, 6);
    g.addEdge(7, 2);    g.addEdge(9, 2);
    g.addEdge(9, 8);    g.addEdge(8, 2);
    g.addEdge(7, 4);

    visited = new char[g.N];
    for (i = 0; i < g.N; i++)
        visited[i] = 0;

    myUser=7;
    getAllFriends(7,1,1);
   // getAllFriends(7,1,2);


   return 0;
}


