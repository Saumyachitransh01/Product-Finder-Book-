#include <bits/stdc++.h>

using namespace std;

int n, m;
const int N = 1e5 + 3;
const int inf = 1e7;
vector<vector<int>> g[N];
int cost = 0;
vector<int> dist(N), parent(N);
vector<bool> vis(N);
const int INF = 1e9;
void change(vector<vector<char>> &A,int x, int y){
    A[x][y] = '*';
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    for(int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if(cx>=0 and cx<A.size() and cy>=0 and cy<A[0].size() and A[cx][cy] == 'O'){
            change(A, cx, cy);
        }
    }
}
void primsMST(int source)
{
    for (int i = 0; i < n; i++)
        dist[i] = INF;
}

// int main(){
//     cin>>n>>m;
//     vector<int> dis(n+1, inf);
//     vector<vector<pair<int, int>>> graph(n+1);
//     for(int i=0; i<m; i++){
//         int u, v, w;
//         cin>>u>>v>>w;
//         graph[u].push_back({v,w});
//         graph[v].push_back({u,w});
//         // g[u].push_back({v,w});
//         // g[v].push_back({u,w});
//     }
//     int source;cin>>source;
//     dis[source] = 0;
//     set<pair<int,int>> s;
//     s.insert({0, source});
//     while(!s.empty()){
//         auto x = *(s.begin());
//         s.erase(x);
//         for(auto it : graph[x.second]){
//             if(dis[it.first] > dis[x.second] + it.second){
//                 s.erase({dis[it.first], it.first});
//                 dis[it.first] = dis[x.second]+it.second;
//                 s.insert({dis[it.first], it.first});
//             }
//         }
//     }
//     for(int i=1; i<=n; i++){
//             if(dis[i]<inf)
//                 cout<<dis[i]<<" ";
//             else
//                 cout<<-1<<" ";
//         }
//         cout<<endl;
//     // primsMST(0);
//     // cout<<cost;
// }

// Bellman Ford
int main()
{
    // cin>>n>>m;
    // vector<vector<int>> edges;
    // for(int i=0; i<m; i++){
    //     int u, v, w;
    //     cin>>u>>v>>w;
    //     edges.push_back({u,v,w});
    // }
    // int src; cin>>src;
    // vector<int> dist(n, INF);
    // dist[src] = 0;
    // bool change;
    // for(int it=0; it<n-1;it++){
    //     change = false;
    //     for(auto e : edges){
    //         int u = e[0];
    //         int v = e[1];
    //         int w = e[2];
    //         if(dist[v]>w + dist[u])
    //             change = true;
    //         dist[v] = min(dist[v],w + dist[u]);
    //     }
    // }
    // if(change)
    //     cout<<"Negative Cycle detected\n";
    // for(auto i : dist)
    //     cout<<i<<" ";
    // cout<<endl;
    // vector<vector<int>> graph = {   {0,5,INF,10},
    //                                 {INF,0,3,INF},
    //                                 {INF,INF, 0,1},
    //                                 {INF,INF,INF,0}
    //                             };
    // int n = graph.size();
    // vector<vector<int>> dist = graph;
    // for(int k=0; k<n; k++)
    //     for(int i=0;i<n;i++)
    //         for(int j=0; j<n; j++)
    //             if(dist[i][k] + dist[k][j]< dist[i][j])
    //                 dist[i][j] = dist[i][k] + dist[k][j];
    // for(int i=0; i<n; i++){
    //      for(int j=0; j<n;j++){
    //         if(dist[i][j]==INF)
    //             cout<<"INF ";
    //         else
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }      
    // SNAKES AND LADDERS
    // int ladder, snake;
    // cin>>ladder;
    // map<int, int> lad;
    // map<int, int> sna;
    // for(int i=0; i<ladder; i++){
    //     int u,v;
    //     cin>>u>>v;
    //     lad[u] = v;
    // }
    // cin>>snake;
    // for(int i=0;i<snake;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     sna[u] = v;
    // }
    // int moves = 0;
    // queue<int> q;
    // q.push(1);
    // bool found = false;
    // vector<int> vis(101, 0);
    // vis[1] = true;
    // while(!q.empty() and !found){
    //     int sz = q.size();
    //     while(sz--){
    //         int t = q.front();
    //         q.pop();
    //         for(int die=1; die<=6; die++){
    //             if(t + die == 100)
    //                 found = true;
    //             if(t+die<=100 and lad[t+die] and !vis[lad[t+die]]){
    //                 vis[lad[t+die]] = true;
    //                 if(lad[t+die] == 100)
    //                     found = true;
    //                 q.push(lad[t+die]);
    //             }
    //             else if(t+die <= 100 and sna[t+die] and !vis[sna[t+die]]){
    //                 vis[sna[t+die]] = true;
    //                 if(sna[t+die] == 100)
    //                     found = true;
    //                 q.push(sna[t+die]);
    //             }else if(t+die <= 100 and !vis[t+die] and !sna[t+die] and !lad[t+die]){
    //                 vis[t+die] = true;
    //                 q.push(t+die);
    //             }
    //         }
    //     }
    //     moves++;
    // }
    // if(found)   
    //     cout<<moves;
    // else
    //     cout<<-1;
    // cout<<endl;
    // SURROUNDED REGION
    // cin>>n>>m;
    // vector<vector<char>> A(n, vector<char>(m));
    // for(int i=0; i<n; i++)
    //     for(int j=0;j<m;j++)    
    //         cin>>A[i][j];
    // for(int i=0; i<n; i++)
    //     for(int j=0;j<m; j++)
    //         if(i==0 or i==n-1 or j==0 or j==m-1)
    //             if(A[i][j] == 'O')
    //                 change(A,i,j);
    // for(int i=0;i<n;i++)
    //     for(int j=0;j<m;j++)
    //         if(A[i][j] == 'O')
    //             A[i][j] = 'X';
    // for(int i=0;i<n; i++)
    //     for(int j=0; j<m; j++)
    //         if(A[i][j] == '*')
    //             A[i][j] = 'O';
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++)
    //         cout<<A[i][j]<<" ";
    //     cout<<endl;
    // }
    // FIBONACCI
    
}