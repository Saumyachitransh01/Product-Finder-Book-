#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define n 100

class STACK{
    int* arr;
    int top;

    public:
    STACK(){
        arr=new int[n];
        top=-1;
    }
    void push(int x){
        if(top==n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop(){
        if(top==-1){
            cout<<"Empty stack"<<endl;
            return;
        }           
        top--;
    }
    int Top(){
        if(top==-1){
            cout<<"No element in stack"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool empty(){
        return top==-1;
    }
};

class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    Stack(){
        N=0;
    }
    void push(int val){
        q2.push(val);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }
    void pop(){
        q1.pop();
        N--;
    }
    int top(){
        return q1.front();
    }
    int size(){
        return N;
    }
};

class Stck{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:
    Stck(){
        N=0;
    }
    void pop(){
        if(q1.empty()){
            return;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;
        queue<int> temp = q1;
        q1=q2;
        q2=temp;
    }

    void push(int val){
        q1.push(val);
        N++;
    }
    int top(){
        if(q1.empty())
            return -1;
        
        while (q1.size() !=1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        q2.push(ans); 
        queue<int> temp = q1;
        q1=q2;
        q2=temp;
        return ans;      
    }
};

int get_max_area(vector<int> a){
    int m = a.size(),ans=0,i=0;
    a.push_back(0);
    stack<int> st;
    while(i<m){
        while(!st.empty() && a[st.top()]>a[i]){
            int t = st.top();
            int h = a[t];
            st.pop();
            if(st.empty())
                ans = max(ans, h*i);
            else{
                int len=i-st.top()-1;
                ans = max(ans,h*len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int rain_water(vector<int> a){
    stack<int> st;
    int x = a.size(), ans=0;
    for(int i=0;i<x;i++){
        while(!st.empty() and a[st.top()] < a[i]){
            int cur = st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int diff=i-st.top()-1;
            ans += (min(a[st.top()],a[i])-a[cur])*diff;      
        }
        st.push(i);
    }
    return ans;
}

vector<int> stockspan(vector<int> prices){
    vector<int> ans;
    stack<pair<int,int>> s;
    for(auto price:prices){
        int days = 1;
        while(!s.empty() && s.top().first <= price){
            days+=s.top().second;
            s.pop();
        }
        s.push({price,days});
        ans.push_back(days);
    }
    return ans;
}

int main(){
    // Stck st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // cout<<st.top();
    // st.push(2);
    // st.push(3);
    // st.push(4);endl;
    // st.pop();
    // cout<<st.top()<<endl;
    // st.pop();
    // cout<<st.top()<<endl;
    // st.pop();
    // cout<<st.top()<<endl;
    // st.pop();
    // cout<<st.top()<<endl;
    // cout<<st.size()<<endl;
    // vector<int> v = {2,1,5,6,2,3};
    // cout<<get_max_area(v)<<endl;
    // vector<int> a{0,1,0,2,1,0,1,3,2,1,2,1};
    // cout<<rain_water(a)<<endl;
    // string s;
    // cin>>s;
    // stack<char> st;
    // bool ans=false;
    // for(int i=0;i<s.size();i++){
    //     if(s[i] == '+' or s[i]=='-' or s[i]=='/' or s[i]=='*' )
    //         st.push(s[i]);
    //     else if(s[i]=='(')
    //         st.push(s[i]);
    //     else if(s[i]==')'){
    //         if(st.top()=='('){
    //             ans=true;
    //         }
    //         while(s[i]=='+' or s[i]=='-' or s[i]=='/' or s[i]=='*' )
    //             st.pop();
    //         st.pop();
    //     }
    // }
    // cout<<ans<<endl;

    // vector<int> a={100,80,60,70,60,75,85};
    // vector<int> res = stockspan(a);
    // for(auto i : res)
    //     cout<<i<<" ";
    // cout<<endl;

    // THREE SUM PROBLEM
    // int N;cin>>N;
    // int target;cin>>target;
    // vector<int> a(N);
    // for(auto &i:a)
    //     cin>>i;
    // bool found = false;
    // sort(a.begin(),a.end());
    // for(int i=0;i<N;i++){
    //     int lo=i+1,hi=N-1;
    //     while(lo<hi){
    //         int curr = a[i]+a[lo]+a[hi];
    //         if(curr==target)
    //             found=true;
    //         if(curr<target)
    //             lo++;
    //         else
    //             hi--;
    //     }
    // }
    // if(found) cout<<"True"<<endl;
    // else cout<<"False"<<endl;

    // MAX CONSEQUTIVE ONES
    // int N; cin>>N;
    // int k;cin>>k;
    // vector<int> a(N);
    // for(auto &i: a)
    //     cin>>i;
    // int zero=0,i=0,ans=0;
    // for(int j=0; j<N; j++){
    //     if(a[j] == 0)
    //         zero++;
    //     while(zero>k){
    //         if(a[i] == 0)
    //             zero--;
    //         i++;
    //     }
    //     ans = max(ans,j-i+1);
    // }
    // cout<<ans<<endl;

    // LONGEST SUBSTRING
    // string s;
    // cin>>s;
    // vector<int> dict(256,-1);
    // int maxLen=0, start=-1;
    // for(int i=0;i<s.size();i++){
    //     if(dict[s[i]]>start)
    //         start = dict[s[i]];
    //     dict[s[i]]=i;
    //     maxLen = max(maxLen,i-start);
    // }
    // cout<<maxLen<<endl;
    return 0;
}