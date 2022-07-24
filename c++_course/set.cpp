#include <bits/stdc++.h>
#include <set>
#include<unordered_set>

using namespace std;
// set, multiset, unordered_set
int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);

    for(auto i:s)
        cout<<i<<" ";
    cout<<endl;
    cout<<s.size()<<"\n";
    s.erase(s.find(3));
    for(auto i:s)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}

int findMinDiff(int arr[], int n, int m){
    if(n==0 || m == 0)
        return 0;
    
    if(n > m)
        return -1;

    sort(arr, arr + n);

    int min_diff = INT_MAX;
    
    for(int i = 0; i + m - 1 < n; i++){
        int diff = arr[i + m - 1] - arr[i];
        if(diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}