#include<bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;

const int N = 1e3+2,MOD = 1e9+7;
int dp[200][200];

int dpo[200][200][200];
int val[N], wt[N];
vector<int> a;
const int inf = 1e9;
int coinChange(vi &a, int n, int x){
    int dp[N][N];
    if(x == 0)
        return 1;
    if(x < 0)   
        return 0;
    if(n <= 0)
        return 0;
    if(dp[n][x] != -1)
        return dp[n][x];

    dp[n][x] =  coinChange(a,n,x-a[n-1])+coinChange(a,n-1,x);
    return dp[n][x];
}
int knapSack(int n, int w){
    int dp[N][N];
    if(w<=0)
        return 0;
    if(n <= 0)
        return 0;
    if(dp[n][w] != -1)
        return dp[n][w];
    if(wt[n-1] > w)
        dp[n][w] = knapSack(n-1,w);
    else
        dp[n][w] = max(knapSack(n-1,w),knapSack(n-1,w-wt[n-1]) + val[n-1]);
    return dp[n][w];
}
int lis(vi &a, int n){
    int dp[N];
    if(dp[n] != -1)
        return dp[n];
    dp[n] = 1;
    rep(i, 0,n){
        if(a[n] > a[i])
            dp[n] = max(dp[n], 1+lis(a,i));
    }
    return dp[n];
}
int lcs(string &s1, string &s2, int n, int m){
    if(n==0 || m==0)
        return 0;
    if(dp[n][m] != -1)
        return dp[n][m];
    if(s1[n-1] == s2[m-1])
        dp[n][m] =  1 + lcs(s1,s2,n-1,m-1);
    else
        dp[n][m] =  max(lcs(s1, s2, n, m-1), lcs(s1,s2,n-1,m));
    return dp[n][m];  
}
int mcm(int i, int j){
    if(i==j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = MOD;
    rep(k,i,j)
        dp[i][j] = min(dp[i][j], mcm(i,k) + mcm(k+1,j)+a[i-1]*a[k]*a[j]);
    
    return dp[i][j]; 
}
int solve(int i, int j){
    if(i == j)
        return a[i];
    if(i>j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int l = a[i] + min(solve(i+2,j),solve(i+1,j-1));
    int r = a[j] + min(solve(i,j-2), solve(i+1,j-1));

    return  dp[i][j] = max(l,r);
}
int LCS(string &s1,string &s2,string &s3, int i, int j, int k){
    if(i==0 || j==0 || k==0)
        return 0;
    if(dpo[i][j][k] != -1)
        return dpo[i][j][k];
    if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
        return dpo[i][j][k] = 1 + LCS(s1,s2,s3,i-1,j-1,k-1);
    int l = LCS(s1,s2,s3,i-1,j,k);
    int r = LCS(s1,s2,s3,i,j-1,k);
    int p = LCS(s1,s2,s3,i,j,k-1);
    return dpo[i][j][k] = max({l,r,p});
}
int main(){
    // rep(i,0,N)
    //         dp[i] = -1;
    // int n;
    // cin>>n;
    // Fibonacci
    // vector<int> dp(n+1);
    // dp[0] = 0;
    // dp[1] = 0;
    // dp[2] = 1;
    // for(int i=3;i<=n;i++)
    //     dp[i] = dp[i-1] + dp[i-2];
    // cout<<dp[n]<<endl;  
    // for(int i=0;i<N;i++)
    //     dp[i] = MOD;
    // cout<<MinSquare(n)<<endl;
    // 
    // MIN SQUARE
    // vector<int> dp(n+1,MOD);
    // dp[0] = 0;
    // dp[1] = 1;
    // dp[2] = 2;
    // dp[3] = 3;
    // for(int i=1; i*i<=n;i++)
    //     for(int j=0;i*i+j<=n; j++)
    //         dp[i*i + j] = min(dp[i*i + j], 1+dp[j]);
    // cout<<dp[n]<<endl;
    // COIN CHANGE
    // vi a(n);
    // rep(i,0,n)
    //     cin>>a[i];
    // int x;
    // cin>>x;
    // vvi dp(n+1, vi(x+1, 0));
    // dp[0][0] = 1;
    // rep(i,1,n+1){
    //     rep(j,0,x+1){
    //         if(j-a[i-1] >= 0)
    //             dp[i][j] += dp[i][j-a[i-1]];
    //         dp[i][j] += dp[i-1][j];
    //     }
    // }
    // cout<<dp[n][x]<<endl;
    // KNAPSACK
    // rep(i,0,n)
    //     cin>>wt[i];
    // rep(i,0,n)
    //     cin>>val[i];
    // int w;
    // cin>>w;
    // cout<<knapSack(n,w)<<endl;
    // LIS
    // vi a(n);
    // rep(i,0,n)
    //     cin>>a[i];
    // // cout<<lis(a,n-1)<<endl;
    // vi dp(n, 1);
    // int ans = 0;
    // rep(i,1,n){
    //     rep(j,0,i)
    //         if(a[i]>a[j])
    //             dp[i] = max(dp[i],1+dp[j]);
    //     ans = max(ans, dp[i]);
    // }
    // cout<<ans<<endl;
    // LCS
    // rep(i,0,N)
    //     rep(j,0,N)
    //         dp[i][j] = -1;
    // string s1, s2;
    // cin>>s1>>s2;
    // int n = s1.size(), m = s2.size();
    // // cout<<lcs(s1, s2, n, m)<<endl;
    // vvi dp(n+1, vi(m+1, -1));
    // rep(i,0,n+1){
    //     rep(j,0,m+1){
    //         if(i==0 || j==0){
    //             dp[i][j] = 0;
    //             continue;
    //         }
    //         if(s1[i-1] == s2[j-1])
    //             dp[i][j] = 1 + dp[i-1][j-1];
    //         else    
    //             dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    //     }
    // }
    // cout<<dp[n][m]<<endl;
    // int n;
    // cin>>n;
    // // memset(dp, -1, sizeof dp);
    // rep(i,0,n)
    //     cin>>a[i];
    // rep(i,1,n)
    //     dp[i][i] = 0;
    // rep(l,2,n){
    //     rep(i,1,n-l+1){
    //         int j=i+l-1;
    //         dp[i][j] = MOD;
    //         rep(k,i,j){
    //             dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
    //         }
    //     }
    // }
    // cout<<dp[1][n-1]<<endl;
    // cout<<mcm(1,n-1)<<endl;
    // Minimum JUMPS
    // int n; cin>>n;
    // vector<int> arr(n);
    // for(auto &i : arr)
    //     cin>>i;
    // vector<int> jumps(n,inf);
    // if(arr[0] == 0){
    //     cout<<inf<<" ";
    //     return 0;
    // }
    // jumps[0] = 0;
    // for(int i=1;i<n;i++)
    //     for(int j=0;j<i; j++)
    //         if(i <= (j+arr[j]))
    //             jumps[i] = min(jumps[i], jumps[j]+1);
    // cout<<jumps[n-1]<<endl;
    // memset(dp,-1,sizeof(dp));
    // int n;
    // cin>>n;
    // a = vector<int>(n);
    // for(auto &i : a)
    //     cin>>i;
    // cout<<solve(0,n-1)<<endl;
    // Number of subsequence
    // int n;
    // cin>>n;
    // string s; cin>>s;
    // int e=1, a=0, ab=0, abc=0;
    // rep(i,0,n){
    //     if(s[i] == 'a')
    //         a += e;
    //     else if(s[i] == 'b')
    //         ab+=a;
    //     else if(s[i] == 'c')
    //         abc += ab;
    //     else if(s[i] == '?'){
    //         abc = 3*abc + ab;
    //         ab = 3*ab + a;
    //         a = 3*a + e;
    //     }
    // }
    // cout<<abc<<endl;   
    // Fibonacci
    // int n; cin>>n;
    // vector<int> fib(n+2,0);
    // fib[0] = 1;
    // fib[1] = 1;
    // for(int i = 2; i<=n+1; i++)
    //     fib[i] = fib[i-1] + fib[i-2];
    // cout<<fib[n+1]<<endl;
    // O-N Knapsack 
    // int n=5, w=11;
    // vector<int> wt = {3,2,4,5,1};
    // vector<int> val = {4,3,5,6,1};
    // vector<int> dp(w+1,0);
    // for(int j=0;j<=w;j++)
    //     for(int i=0; i<n; i++)
    //         if(j - wt[i] >= 0)
    //             dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
    // cout<<dp[w]<<endl;
    // Kedane Algo
    // int n;
    // cin>>n;
    // vi a(n);
    // rep(i,0,n)
    //     cin>>a[i];
    // int curr=0, maxTill = 0;
    // rep(i,0,n){
    //     curr += a[i];
    //     maxTill = max(curr, maxTill);
    //     if(curr<0)
    //         curr = 0;
    // }
    // cout<<maxTill<<endl;
    // Bitonic subequence
    // int n=8;
    // vi a = {1,11,2,10,4,5,2,1};
    // vi forward(n,1), backward(n,1);
    // for(int i=0;i<n;i++)
    //     for(int j=0;j<i;j++)
    //         if(a[i]>a[j])
    //             forward[i] = max(forward[i], 1+forward[j]);
    // for(int i=n-1;i>=0;i--)
    //     for(int j=n-1;j>i;j--)
    //         if(a[i] > a[j])
    //             backward[i] = max(backward[i], 1+backward[j]);
    // int ans = 0;
    // for(int i=0;i<n;i++)
    //     ans = max(ans, forward[i]+backward[i]-1);
    // cout<<ans<<endl;
    // Friends Pair
    // int n;cin>>n;
    // vi dp(n+1,0);
    // dp[0] = 1;
    // dp[1] = 1;
    // for(int i=2;i<=n;i++){
    //     dp[i] = dp[i-1]+(i-1)*dp[i-2];
    // }
    // cout<<dp[n]<<endl;
    // UGLY NUMBER
    // int n=20;
    // int c2(0),c3(0),c5(0);
    // vi dp(n+1);
    // dp[0]=1;
    // for(int i=1;i<=n;i++){
    //     dp[i] = min({2*dp[c2],3*dp[c3],5*dp[c5]});
    //     if(2*dp[c2] == dp[i])
    //         c2++;
    //     if(3*dp[c3] == dp[i])
    //         c3++;
    //     if(5*dp[c5] == dp[i])
    //         c5++;
    // }
    // for(int i=0;i<n;i++)
    //     cout<<dp[i]<<" ";
    // cout<<endl;
    // LCS with 3
    memset(dpo,-1,sizeof(dpo));
    string s1; cin>>s1;
    string s2; cin>>s2;
    string s3; cin>>s3;
    cout<<LCS(s1,s2,s3,s1.size(), s2.size(), s3.size())<<endl;

    return 0;
}