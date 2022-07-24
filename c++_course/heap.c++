#include <iostream>
#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

void heapify(vector<int> &a, int n, int i){
    int maxIdx = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && a[l] > a[maxIdx])
        maxIdx = l;
    if(r<n && a[r] > a[maxIdx])
        maxIdx = r;
    if(maxIdx != i){
        swap(a[i], a[maxIdx]);
        heapify(a,n,maxIdx);
    }
}
void heapsort(vector<int> &a){
    int n = a.size();
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);

    for(int i=n-1;i>0;i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

priority_queue<int, vi, greater<int>> pqmin;
priority_queue<int, vi, greater<int>> pqmax;

void insert(int x){
    if(pqmin.size() == pqmax.size()){
        if(pqmax.size() == 0){
            pqmax.push(x);
            return;
        }
        if(x < pqmax.top())    
            pqmax.push(x);
        else 
            pqmin.push(x);
    }
    else{
        {
            if(pqmax.size() > pqmin.size()){
                if(x >= pqmax.top())
                    pqmin.push(x);
                else{
                    int temp = pqmax.top();
                    pqmax.pop();
                    pqmin.push(temp);
                    pqmax.push(x);
                }
            }else{
                if(x <= pqmin.top())
                    pqmax.push(x);
                else{
                    int temp = pqmin.top();
                    pqmin.pop();
                    pqmax.push(temp);
                    pqmin.push(x);
                }
            }
        }
    }   
}
double findMedian(){
    if(pqmin.size() == pqmax.size())
        return (pqmin.top() + pqmax.top())/2.0;
    else if(pqmax.size() > pqmin.size())
        return pqmax.top();
    else
        return pqmin.top(); 
}

void mergeK(){
    int k;
    cin>>k;
    vector<vector<int>> a(k);
    for(int i=0;i<k;i++){
        int size;
        cin>>size;
        a[i] = vector<int>(size);
        for(int j=0;j<size;j++){
            cin>>a[i][j];
        }
    }
    vector<int> idx(k,0);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<int>> pq;
    for(int i=0;i<k;i++){
        pair<int, int> p;
        p.first = a[i][0];
        p.second = i;
        pq.push(p);
    }
    vector<int> ans;

    while(!pq.empty()){
        pair<int, int> x = pq.top();
        pq.pop();
        ans.push_back(x.first);
        if(idx[x.second]+1 < a[x.second].size()){
            pair<int,int> p;
            p.first = a[x.second][idx[x.second]+1];
            p.second = x.second;
            pq.push(p);
        }
        
        idx[x.second] += 1;
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    // int n;
    // cin>>n;
    // vector<int> a(n);
    // for(int i=0; i<n;i++)
    //     cin>>a[i];
    // heapsort(a);
    // for(int i=0;i<n;i++)
    //     cout<<a[i]<<" ";

    // priority_queue<int, vector<int>> pq;
    // pq.push(2);
    // pq.push(3);
    // pq.push(1);
    // cout<<pq.top()<<endl;
    // pq.pop();
    // cout<<pq.top()<<endl;
    // cout<<endl;
    // priority_queue<int, vector<int>, greater<int>> pqm;
    // pqm.push(2);
    // pqm.push(1);
    // pqm.push(3);
    // cout<<pqm.top()<<endl;
    // pqm.pop();
    // cout<<pqm.top()<<endl;
    // insert</int>(10);
    // cout<<findMedian()<<endl;
    // insert(15);
    // cout<<findMedian()<<endl;
    // insert(21);
    // cout<<findMedian()<<endl;
    // insert(30);
    // cout<<findMedian()<<endl;
    // insert(18);
    // cout<<findMedian()<<endl;
    // insert(19);
    // cout<<findMedian()<<endl;
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    priority_queue<int, vector<int>> pq;

    for(int i=0;i<n;i++)
        pq.push(a[i]);
    int sum=0;
    int cnt=0;
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
        cnt++;
        if(sum>=k)
            break;
    }
    if(sum<k)
        cout<<"-1"<<endl;
    else 
        cout<<cnt;
    cout<<endl;
    return 0;
}