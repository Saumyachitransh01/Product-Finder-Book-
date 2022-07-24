#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    double v1 = (double)p1.first/p1.second;
    double v2 = (double)p2.first/p2.second;
    return v1>v2;
}

int main(){
    // INDIAN CURRENCY
    // int n;
    // cin>>n;
    // vector<int> a(n);
    // for(int i=0; i<n; i++)
    //     cin>>a[i];
    // int x;
    // cin>>x;
    // sort(a.begin(), a.end(), greater<int>());
    // int ans = 0;
    // for(int i=0;i<n;i++){
    //     ans += x/a[i];
    //     x -= x/a[i]*a[i];
    // }
    // cout<<ans<<endl;
    // ACTIVITY SELECTION
    // int n; cin>>n;
    // vector<vector<int>> v;
    // for(int i=0;i<n;i++){
    //     int start, end;
    //     cin>>start>>end;
    //     v.push_back({start, end});
    // }
    // sort(v.begin(), v.end(),[&](vector<int> &a, vector<int> &b){
    //     return a[1] < b[1];
    // });
    // int take = 1;
    // int end = v[0][1];
    // for(int i=1; i<n; i++){
    //     if(v[i][0] >= end){
    //         take++;
    //         end = v[i][1];
    //     }
    // }
    // cout<<take<<endl;
    // FRACTIONAL KNAPSACK  
    // int n;
    // cin>>n;
    // vector<pair<int, int>> a(n);
    // for(int i=0;i<n;i++){
    //     cin>>a[i].first>>a[i].second;
    // }
    // int w;
    // cin>>w;
    // sort(a.begin(), a.end(), compare);
    // int ans = 0;
    // for(int i=0;i<n;i++){
    //     if(w >= a[i].second){
    //         ans += a[i].first;
    //         w -= a[i].second;
    //         continue;
    //     }
    //     double vw = (double)a[i].first/a[i].second;
    //     ans += vw*w;
    //     w=0;
    //     break;
    // }
    // cout<<ans<<endl;
    // OPTIMAL MERGE PATTERN
    // int n;
    // cin>>n;
    // vector<int> a(n);
    // for(int i=0;i<n;i++)
    //     cin>>a[i];
    // priority_queue<int, vector<int>, greater<int>> minheap;
    // for(int i=0;i<n;i++)
    //     minheap.push(a[i]);
    // int ans = 0;
    // while(minheap.size() > 1){
    //     int e1 = minheap.top();
    //     minheap.pop();
    //     int e2 = minheap.top();
    //     minheap.pop();
    //     ans += e1+e2;
    //     minheap.push(e1+e2); 
    // }
    // cout<<ans<<endl;
    // EXPEDI
    // int t;
    // cin>>t;
    // while(t--){
    //     int n;
    //     cin>>n;
    //     vector<pair<int, int> > a(n);
    //     for(int i=0;i<n;i++){
    //         cin>>a[i].first>>a[i].second;
    //     }
    //     int l, p;
    //     cin>>l>>p;
    //     for(int i=0;i<n;i++)
    //         a[i].first = l - a[i].first;
    //     sort(a.begin(), a.end());
    //     int ans=0;
    //     int curr = p;
    //     priority_queue<int, vector<int> > pq;
    //     bool flag=0;
    //     for(int i=0; i<n; i++){
    //         if(curr >= l)
    //             break;
    //         while(curr < a[i].first){
    //             if(pq.empty()){
    //                 flag = 1;
    //                 break;
    //             }
    //             ans++;
    //             curr += pq.top();
    //             pq.pop();
    //         }
    //         if(flag)
    //             break;

    //         pq.push(a[i].second);
    //     }
    //     if(flag){
    //         cout<<"-1"<<endl;
    //         continue;
    //     }
    //     while(!pq.empty() && curr<l){
    //         curr += pq.top();
    //         pq.pop();
    //         ans++;
    //     }
    //     if(curr<l){
    //         cout<<"-1"<<endl;
    //         continue;
    //     }
    //     cout<<ans<<endl;
    // }
    // MIN AND MAX DIFF
    // int n;cin>>n;
    // vector<int> a(n);
    // for(auto &i : a)
    //     cin>>i;
    // sort(a.begin(), a.end());
    // long long mn=0, mx=0;
    // for(int i=0; i<n/2; i++){
    //     mx += (a[i+n/2]- a[i]);
    //     mn += (a[2*i+1] - a[2*i]);
    // }
    // cout<<"Max = "<<mx<<" and Min = "<<mn;
    // cout<<endl;
    // return 0;   
}