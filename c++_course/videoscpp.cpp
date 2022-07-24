#include <iostream>
#include <math.h>
#include<climits>
#include <algorithm>
#include "bits/stdc++.h"
#include <string>
using namespace std;

bool checkTriplet(int a, int b, int c)
{

    if (((a * a) == ((b * b) + (c * c))) || ((c * c) == ((b * b) + (a * a))) || (b * b == ((a * a) + (c * c))))
        return true;
    return false;
}
void convertBase(int num, int curr, int into)
{
    int ans = 0, x = 1;
    int n = num;
    while (n > 0)
    {
        int y = n % into; 
        ans += x * y;
        x *= curr;
        n /= into; 
    }
    cout<<num <<" converted from base "<<curr<<" into base "<<into<<" = " << ans << endl;
}
int binarySearch(int ar[], int n, int k){
    
    int s =0, e=n;
    int mid = (s+e)/2;
    if(ar[mid]==k)
        return mid;
    else if(ar[mid]>k){
        e=mid-1;
    }else
        s = mid+1;
    return -1;
}
int getBit(int n, int pos){
    return ((n & (1 << pos)) != 0);
}
int setBit(int n, int pos){
    return (n | (1 << pos));
}
int clearBit(int n, int pos){
    int mask = ~(1<<pos);
    return (n & mask);
}
bool isPower(int n){
    return (n && !(n & n-1));
}
int updateBit(int n, int pos, int value){
    clearBit(n, pos);
    return setBit(n, value);
}
int numOfOne(int n){
    int count = 0;
    while(n){
        n = n & (n-1);
        count++;
    }
    return count;
}
void subsets(int arr[], int n){
    for(int i=0;i<(1<<n); i++){
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }cout<<endl;
    }
}
void unique(int arr[], int n){
    int xorsum = 0;
    for(int i=0 ;i<n; i++){
        xorsum = xorsum^ arr[i];
    }
    int tempxor = xorsum;
    int setbit = 0;
    int pos = 0;
    while(setbit != 1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int newxor=0;
    for(int i=0; i<n; i++){
        if(setBit(arr[i], pos-1)){
            newxor = newxor^arr[i];
        }
    }
    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
}
void primeSeive(int n){
    int prime[100] = {0};
    for(int i=2; i<=n;i++){
        if(prime[i] == 0){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = 1;
            }
        }
    }
    for(int i=2; i<=n;i++){
        if(prime[i] == 0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
void primeFactor(int n){
    int spf[100] = {0};
    for(int i=2; i<=n;i++){
        spf[i] = i;
    }
    for(int i=2; i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i; j<=n; j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
    while(n!=1){
        cout<<spf[n]<<" ";
        n /=spf[n];
    }
}
int gcd(int a, int b){
    int rem;
    while(b!=0){
        rem = a%b;
        a=b;
        b=rem;
    }
    return a;
}
int power( int a, int n){
    if(n == 0)
        return 1;
    int prev = power(a,n-1);
    return a*prev;
}
int fact(int n){
    if(n==0)
        return 1;
    return fact(n-1)*n;
}
int fib(int n){
    if(n==0 || n==1)
        return n;
    
    return fib(n-1)+fib(n-2);
}
int sorted(int arr[], int n){
    if(n==1)
     return true;
    int prevArr = sorted(arr+1,n-1);
    return (arr[0]<arr[1] && prevArr);
}
void dec(int n){
    if(n==0)
        return;
    dec(n-1);
    cout<<n<<endl;
    
}
int main()
{
    // primeFactor(90);
    // cout<<gcd(24,42)<<endl;
    // cout<<power(2,4)<<endl;
    // cout<<fact(5)<<endl;
    // cout<<fib(5)<<endl;
    // int arr[] = {1,2,3,4,5,6,7,8};
    // cout<<sorted(arr,8)<<endl;
    dec(8);
    return 0;
}