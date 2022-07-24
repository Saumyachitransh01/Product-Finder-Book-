#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPalindrome(int n){
    int temp = n, num=0;
    while(temp!=0){
        num *= 10;
        num += temp%10;
        temp/=10;
    }
    if(num==n)
        return true;
    else return false;
}

int findPalindrome(vector<int> arr, int k){
    int num = 0;
    for(int i=0;i<k;i++)
        num = num*10 + arr[i];
    if(isPalindrome(num))
        return 0;
    for (int j = 0; j < arr.size(); j++)
    {
        num = (num%(int)pow(10, k-1))*10 + arr[j];
        if(isPalindrome(num))
            return j-k+1;
    }
    return -1;
}

bool isPerfect(int n){
    int sum=1;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
            if(i == n/i)
                sum += i;
            else
                sum += i + n/i;
        }
    }
    if(sum == n && n!=1)
        return true;
    return false;
}

int maxSum(int arr[], int n, int k){
    if(n<k){
        cout<<"Invalid values"<<endl;
        return -1;
    }
    int res = 0;
    for(int i=0;i<k;i++){
        res+=arr[i];
    }
    int sum=res;
    for(int i=k; i<n; i++){
        sum+=arr[i] - arr[i-k];
        res = max(res, sum);
    }
    return res;
}

int maxNumberOfPerfection(int arr[], int n, int k){
    for(int i=0;i<n;i++){
        if(isPerfect(arr[i]))
            arr[i] = 1;
        else  
            arr[i] = 0;
    }
    return maxSum(arr, n, k);
}

int main(){
    // vector<int> arr = {2,3,3,2,3,2};
    // int k=4;
    // cout<< findPalindrome(arr,k)<<endl;
    // int ans = findPalindrome(arr,k);
    // if(ans == -1)
    //     cout<<"Palindrome subarray doesn't exist"<<endl;
    // else{
    //     for(int i=ans;i<ans+k;i++)
    //         cout<<arr[i]<<" ";
    //     cout<<endl;
    // }
    int arr[] = {28,2,3,6,496,99,8128,24};
    int k = 4;
    int n = 8;
    cout<<maxNumberOfPerfection(arr, n, k)<<endl;
    return 0;
}