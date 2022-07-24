#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    int id;
    string name;
    string gender;

    void getName(){
         cout<<name<<endl;
    }
    student(){
        cout<<"DEFAULT CONSTRUCTOR";
    }
    student(student &b){
        cout<<"COPY CONSTRUCTOR"<<endl;
        name= b.name;
        id = b.id;
        gender = b.gender;
    }
    student(int i, string names, string genders){
        cout<<"PARAMETERISED"<<endl;
        id = i;
        name = names;
        gender = genders;
    }
    void printInfo(){
        cout<<"\nName is "<<name<<"\nId is "<<id<<"\nGender is "<<gender<<endl;
    }
    ~student(){
        cout<<"DESTRUCTOR"<<endl;
    }
};

class A{
    public:
        int id;
};

int main()
{
    // student a;
    cout<<endl;
    // student arr[3];
    // for(int i=0;i<3;i++){
    //     cout<<"Enter name: ";
    //     cin>>arr[i].name;
    //     cout<<"Enter gender: ";
    //     cin>>arr[i].gender;
    //     cout<<"Enter id: ";
    //     cin>>arr[i].id;
    // }
    // for(int i=0;i<3;i++){
    //     arr[i].printInfo();
    // }
    // student b(2, "Somu","F");
    // student c = b;
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