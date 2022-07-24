#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+2, MOD = 1e9+7;

// struct triplet{
//     int gcd,x,y;
// };

// triplet extendedEuclid(int a, int b){
//     if(b == 0){
//         triplet ans;
//         ans.x = 1;
//         ans.gcd = a;
//         ans.y = 0;
//         return ans; 
//     }
//     triplet smallAns = extendedEuclid(b, a%b);
//     triplet ans;
//     ans.gcd = smallAns.gcd;
//     ans.x = smallAns.y;
//     ans.y = smallAns.x - (a/b)*smallAns.y; 
//     return ans;
// }

int power(int a, int n){
    int ans = 1;
    a %= MOD;
    while( n> 0) {
        if(n&1)
            ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        n = n>>1;
    }
     return ans;
    
}

struct triplet{
    int gcd, x, y;
};

triplet extended(int a, int b){
    if(b == 0){
        triplet ans;     
        ans.x = 1;
        ans.gcd = a;
        ans.y = 0;
        return ans;
    }
    triplet smallA = extended(b, a%b);
    triplet ans;
    ans.gcd = smallA.gcd;
    ans.x = smallA.y;
    ans.y = smallA.x - (a/b)*smallA.y;
    return ans;
}

int multipli(int a, int m){
    triplet temp = extended(a, m);
    return temp.x;
}
int totient[N];

// int power(int a, int n){
//     a%= MOD;
//     int ans=1;
//     while(n>0){
//         if(n&1)
//             ans = (ans*a)%MOD;
//         a = (a*a)%MOD;
//         n = n>>1;
//     }
//     return ans;
// }
// int power(int a, int n){
//     if(n==0)
//         return 1;
//     int p =(power(a, n/2)%MOD);
//     if(n&1)
//         return (((p*p)%MOD)*a)%MOD;
//     else
//         return (p*p)%MOD;
// }

int power(int x, int y, int p){
    int res = 1;
    x = x%p;
    while(y>0){
        if(y&1)
            res = (res*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return res;
}

int modInv(int a, int p){
    return power(a, p-2,p);
}

int modfact(int n, int p){
    if(p <= n)
        return 0;
    int res = (p-1);
    for(int i=n+1;i<p;i++){
        res = (res*modInv(i,p))%p;
    }
    return res;
}

signed main(){
    // int a, b;   
    // cin>>a>>b;
    // triplet ans = extendedEuclid(a, b);
    // cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;

// multiplicative modulo inverse
    // int a, m;
    // cin>>a>>m;
    // cout<<multipli(a,m)<<endl;

    // Totient
    // for(int i=0; i<N; i++)
    //     totient[i] = i;
    // for(int i=2; i<N;i++)
    //     if(totient[i]==i){
    //         for(int j=2*i; j<N;j+=i){
    //             totient[j] *= i-1;
    //             totient[j] /= i;
    //         }
    //         totient[i] = i-1;
    //     }
    // for(int i = 2; i<11; i++){
    //     cout<<totient[i]<<" ";
    // }

    // Binary exponent
    int a, n;
    cin>>a>>n;
    a %= MOD;
    cout<<modfact(a,n)<<endl;

    return 0;
}
