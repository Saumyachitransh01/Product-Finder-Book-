    // rep(i,0,n)
    //     rep(j,0,i)
    //         if(a[i]>a[j])
    //             forward[i] = max(forward[i], 1 + forward[j]);
    // for(int i=n-1; i>=0;i--){
    //     for(int j=n-1;j>i;j--){
    //         if(a[i]>a[j])
    //             backward[i] = max(backward[i], 1 + backward[j]);
    //     }
    // }
    // int ans=0;
    // for(int i=0;i<n;i++){
    //     ans = max(ans, forward[i] + backward[i]-1);
    // }
    // cout<<ans<<endl;