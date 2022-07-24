#include<iostream>
#include "bits/stdc++.h"

#define n 20
using namespace std;

class queue{
    int* arr;
    int front;
    int back;
    public:
    queue(){
        arr = new int[n];
        front = -1;
        back=-1;
    }
    void push(int x){
        if(back==n-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;
        if (front == -1)
            front++;
    }
    void pop(){
        if(front==-1 || front>back){
            cout<<"Empty Queue"<<endl;
            return;
        }
        front++;
    }
    int peek(){
        if(front==-1 || front>back){
            cout<<"Empty Queue"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        return (front==-1 || front>back);
    }
};

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{
    node* front;
    node* back;
    public:
        Queue(){
            front=NULL;
            back=NULL;
        }
    
    void push(int x){
        node* a = new node(x);
        if(front==NULL){
            back=a;
            front=a;
            return;
        }
        back->next=a;
        back=a;
    }
    void pop(){
        if(front==NULL){
            cout<<"Empty Queue"<<endl;
            return;
        }
        node* todelete=front;
        front=front->next;
        delete todelete;
    }
    int peek(){
        if(front==NULL){
            cout<<"Empty Queue"<<endl;
            return -1;
        }
        return front->data;
    }
    bool empty(){
        return front==NULL;
    }
};

class que{
    stack<int> s1;
    // stack<int> s2;
    public:
        void push(int x){
            s1.push(x);
        }     
        int pop(){
            if(s1.empty()){
                cout<<"Queue is empty\n";
                return -1;
            }
            int x = s1.top();
            s1.pop();
            if(s1.empty())
                return x;
            int item = pop();
            s1.push(x);
            return item;
        }
        bool empty(){
            return (s1.empty());
        }
};

int main(){
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<endl;
    q.push(5);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty()<<endl;
    return 0;
}