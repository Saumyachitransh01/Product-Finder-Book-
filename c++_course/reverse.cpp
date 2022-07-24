#include<iostream>

using namespace std;

int main(){
    int n = 12345, rev;
    while(n>0){
        rev *= 10;
        rev += n%10;
        n = n/10;
    }
    cout<<rev<<endl;
}