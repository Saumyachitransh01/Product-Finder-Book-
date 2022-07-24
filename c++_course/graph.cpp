#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>

using namespace std;

const int N=1e5+2;
// bool vis[N];
// vector<int> adj[N];
vector<bool> vis;
vector<int> col;
// int n, m;
vector<vector<int>> adj;
vector<int> components;
void graphIntro(){
    int n, m;
    vi adj[N];
    cin>>n>>m;
    vvi adjm(n+1, vi(n+1, 0));
    for(int i=0;i<m; i++){
        int x, y;
        cin>>x>>y;
        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }
    cout<<"Adjacency matrix of above graph is given by: "<<endl;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++)
            cout<<adjm[i][j]<<" ";
        cout<<endl;
    }
    if(adjm[3][7] == 1)
        cout<<"There is an edge between 3 and 7"<<endl;
    else    
        cout<<"No edge"<<endl;
    cout<<endl<<endl;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<"Adjacency list of the above graph is given by:"<<endl;
    for(int i=1;i<n+1;i++){
        cout<<i<<" -> ";
        vector<int> :: iterator it;
        for(it = adj[i].begin(); it!=adj[i].end(); it++)
            cout<<*it<<" ";
        cout<<endl;
    }
}

void bfs(){
    for(int i=0; i<N; i++)
        vis[i] = 0;
    int n, m;
    cin>>n>>m;
    int x, y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<endl;
        vector<int> :: iterator it;
        for(it=adj[node].begin(); it!=adj[node].end(); it++){
            if(!vis[*it]){
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }  
}

void dfs(int node){
    // preorder
    vis[node] = 1;
    // cout<<node<<" ";
    // inorder  
    vector<int> :: iterator it;
    for(it = adj[node].begin(); it!= adj[node].end();it++){
        if(vis[*it]);
        else  dfs(*it);
    }
    // postorder
    cout<<node<<" ";
}
// FOR UNCYCLIC
// bool iscycle(int src, vector<vector<int>> &adj, vector<bool> &visited, int parent){
//     visited[src] = true;
//     for(auto i : adj[src]){
//         if(i != parent){
//             if(visited[i])
//             return true;
//         if(!visited[i] and iscycle(i, adj, visited, src))
//             return true;
//         }
//     }
//     return false;
// }

// FOR CYCLIC
bool iscycle(int src, vector<vector<int>> &adj, vector<bool> &visited,vector<int> stack){
    stack[src] = true;
    if(!visited[src]){
        visited[src] = true;
        for(auto i : adj[src]){
            if(!visited[i] and iscycle(i, adj, visited, stack))
                return true;
            if(stack[i])
                return true;
        }
        
    }
    stack[src] = false;
        return false;
}

int get_comp(int idx){
    if(vis[idx])
        return 0;
    vis[idx] = true;
    int ans=1;
    for(auto i : adj[idx]){
        if(!vis[i]){
            ans += get_comp(i);
            vis[i] = true;
        }          
    }
    return ans;
}



int main(){
    // int n, m;
    // cin>>n>>m;
    // for(int i=0; i<n;i++)
    //     vis[i] = false;
    // int x, y;
    // for(int i=0;i<m;i++){
    //     cin>>x>>y;
    //     adj[x].push_back(y);
    //     adj[y].push_back(x);
    // }
    // dfs(1);
    // 
    // int n, m; 
    // cin>>n>>m;
    // int cnt = 0;
    // vector<vector<int>> adj(n);
    // vector<int> indeg(n, 0);
    // for(int i=0; i<m; i++){
    //     int u, v;
    //     cin>>u>>v;
    //     adj[u].push_back(v);
    //     indeg[v]++;
    // }
    // queue<int> pq;
    // for(int i=0; i<n;i++){
    //     if(indeg[i]==0) 
    //         pq.push(i);
    // }
    // while(!pq.empty()){
    //     cnt++;
    //     int x = pq.front();
    //     pq.pop();
    //     cout<<x<<" ";
    //     for(auto it : adj[x]){
    //         indeg[it]--;
    //         if(indeg[it] == 0)
    //             pq.push(it);
    //     }
    //     cout<<"\n";
    // }
    // PRESENCE OF CYCLE IN UNIDIRECTED GRAPH
    // int n, m;
    // cin>>n>>m;
    // vector<vector<int>> adj(n);
    // for(int i=0;i<m;i++){
    //     int u, v;
    //     cin>>u>>v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
    // bool cycle = false;
    // vector<bool> visited(n, false);
    // for(int i=0;i<n;i++){
    //     if(!visited[i] and iscycle(i,adj,visited,-1))
    //         cycle = true;
    // }
    // if(cycle)
    //     cout<<"Cycle is present";
    // else    cout<<"Cycle is not present";
    // cout<<endl;
    // PRESENCE OF CYCLE IN DIRECTED GRAPH
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool cycle = false;
    vector<int> stack(n,0);
    vector<bool> visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i] and iscycle(i,adj,visited,stack)){
            cycle=true;
        }
    }
    if(cycle){
        cout<<"Cycle is present";
    }else   
        cout<<"Cycle is NOT present";
    cin>>n>>m;
    adj = vector<vector<int>>(n);
    vis= vector<bool>(n);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++)
        if(!vis[i])
            components.push_back(get_comp(i));
    // for(auto i :components)
    //     cout<<i<<" ";
    long long ans = 0;
    for(auto i:components)
        ans += i*(n-i);
    cout<<(ans/2);
    
    
    return 0;
}