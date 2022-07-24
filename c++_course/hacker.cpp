#include <bits/stdc++.h>

using namespace std;

void calculate(vector<int> a){
    for(int j = 0; j<a.size(); j++){
        int ans=0;
        for(int i=1; i<=a[j];i++){
            a[j] -= i;
            if(a[j]>=0)
                ans++;
            else break;
        }
        cout<<ans<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    calculate(a);
}
     