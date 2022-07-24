#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
const int N = 1e5+3;
vector<int> parent(N);
vector<int> len(N);
int n, m;
vector<int> g[N];
int cost = 0;
bool bipart;

void make_set(int v){
    parent[v] = v;
    len[v] = 1;
}
int find_set(int v){
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(len[a] < len[b])
            swap(a,b);
        parent[b] = a;
        len[a] += len[b];
    }      
}

void color(int u, int curr){
    if(col[u] != -1 and col[u] != curr){
        bipart = false;
        return;
    }
    col[u] = curr;
    if(vis[u])
        return;
    vis[u] = true;
    for(auto i: adj[u])
        color(i, curr xor 1);
}
void bipartate(){
    int n, m;
    bipart = true;
    cin>>n>>m;
    adj = vector<vector<int>>(n);
    vis = vector<bool> (n, false);
    col = vector<int>(n, -1);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0;i<n;i++){
        if(!vis[i])
            color(i,0);
    }
    if(bipart)
        cout<<"Graph is bipart";
    else 
        cout<<"Graph is NOT bipart";
    cout<<endl;
}
int main(){
    for(int i=0; i<N; i++)
        make_set(i);  
    cin>>n>>m;
    vector<vector<int>> edges;
    // for(int i=0;i<m;i++){
    //     int u, v;
    //     cin>>u>>v;
    //     edges.push_back({u,v});
    // }
    // bool cycle = false;
    // for(auto i : edges){
    //     int u = i[0];
    //     int v = i[1];
    //     int x = find_set(u);
    //     int y = find_set(v);
    //     if(x==y)
    //         cycle = true;
    //     else
    //         union_sets(u, v);
    // }
    // if(cycle)
    //     cout<<"Cycle is present";
    // else 
    //     cout<<"Cycle is NOT present";
    // // Kruskal Algorithm
    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    for(auto i : edges){
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = find_set(u);
        int y = find_set(v);
        if(x == y)
            continue;
        else{
            cout<<u<<" "<<v<<"\n";
            cost += w;
            union_sets(u, v);
        }        
    }
    cout<<cost<<endl;
}
