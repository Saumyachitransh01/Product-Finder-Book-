#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

// bool isSafe(int** arr, int x, int y, int n){
//     if(x<n && y<n && arr[x][y]==1)
//         return true;
//     return false;
// }
// 
// bool ratMaze(int** arr, int x, int y, int n, int** solArr){
//     if(x==n-1 && y==n-1){
//         solArr[x][y]=1;
//         return true;
//     }
//     if(isSafe(arr,x,y,n)){
//         solArr[x][y] = 1;
//         if(ratMaze(arr,x+1,y,n,solArr))
//             return true;
//         if(ratMaze(arr,x,y+1,n,solArr))
//             return true;
//         solArr[x][y] = 0;
//         return false;
//     }
//     return false;
// }

bool isSafe(int** arr, int x, int y, int n){
    for (int row = 0; row < x; row++)
        if (arr[row][y] == 1)
            return false;
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0){
        if (arr[row][col] == 1)
            return false;      
        row--;
        col--;
    }
    row = x;
    col = y;
    while (row >= 0 && col < n){
        if (arr[row][col] == 1)
            return false;
        row--;
        col++;
    }
    return true;
}

bool nQueen(int** arr, int x, int n){
    if (x >= n)
        return true;

    for (int col = 0; col < n; col++)
        if (isSafe(arr, x, col, n)){
            arr[x][col] = 1;
            if (nQueen(arr, x + 1, n))
                return true;
            arr[x][col] = 0;
        }
    return false;
}

// void merge(int arr[], int l, int mid, int r){
//     int n1 = mid-l+1;
//     int n2 = r-mid;
//     int a[n1];
//     int b[n2];
//     a[n1]=INT_MAX;
//     b[n2]=INT_MAX;
//     for(int i=0;i<n1;i++){
//         a[i] = a[l+i];
//     }
//     for(int i=0;i<n2;i++){
//         b[i] = a[mid+1+i];
//     }
//     int i=0;
//     int j=0;
//     int k=l;
//     while(i<n1 && j<n2){
//         if(a[i]<b[j]){
//             arr[k]=a[i];
//             k++; 
//             i++;
//         }
//         else{
//             arr[k] = b[j];
//             k++; 
//             j++;
//         }
//     }
//     while(i<n1){
//         arr[k]=a[i];
//             k++; 
//             i++;
//     }
//     while(j<n2){
//         arr[k]=b[j];
//             k++; 
//             j++;
//     }
// }u

void merge(int arr[], int l, int mid, int r)
{

    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];

    a[n1]=INT_MAX;
    b[n2]=INT_MAX;

    for (int i = 0; i < n1; i++){
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++){
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 || j < n2)
    {
        if (a[i] < b[j]){
            arr[k] = a[i];
            k++;i++;
        }
        else{
            arr[k] = b[j];
            k++;j++;
        }
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;i++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}

void quickSort(int arr[], int l, int r){
    if(l<r){
        int pi = partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

bool myCompare(pair<int,int> p1, pair<int, int> p2){
    return p1.first<p2.first;
}

void countSort(int arr[], int n){
    int k=arr[0];
    for(int i=0;i<n;i++)
        k = max(k,arr[i]);

    int count[10] = {0};

    for(int i=0;i<n;i++)
        count[arr[i]]++;

    for(int i=1;i<=k;i++){
        count[i] += count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    } 
    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
}

void dnfSort(int arr[], int n){
    int low=0;
    int mid=0;
    int high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr,low,mid);
            low++;
            mid++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr, mid, high);
            high--;
        }           

    }
}

void waveSort(int arr[], int n){
    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1])
            swap(arr,i,i-1);
        if(arr[i]>arr[i+1] && i<n-1){
            swap(arr,i,i+1);
        }
    }
}

int main(){
    // int n;
    // cin >> n;

    // int **arr = new int *[n];
    // for (int i = 0; i < n; i++){
    //     arr[i] = new int[n];
    //     for (int j = 0; j < n; j++)
    //         arr[i][j] = 0;
    // }

    // if (nQueen(arr, 0, n)){
    //     for (int i = 0; i < n; i++){
    //         for (int j = 0; j < n; j++)
    //             cout << arr[i][j] << " ";
    //         cout << endl;
    //     }   
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //         cin>>arr[i][j];
    // }

    // int** solArr = new int*[n];
    // for(int i=0;i<n;i++){
    //     solArr[i] = new int[n];
    //     for(int j=0;j<n;j++)
    //         solArr[i][j]=0;
    // }

    // cout<<endl;
    // if(ratMaze(arr,0,0,n,solArr)){
    //     for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //         cout<<solArr[i][j]<<" ";
    //     cout<<endl;
    // }
    // }

    // int arr[5] = {5,4,3,2,1};
    // quickSort(arr,0,4);
    // for(int i=0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }

    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);                      //VECTOR BASIC OPERATIONS
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // vector<int>::iterator it;
    // for(it=v.begin(); it!=v.end();it++){
    //     cout<<*it<<" ";
    // }
    // for(auto ele:v){
    //     cout<<ele<<" ";
    // }
    // v.pop_back();
    // vector<int> v2 (3,50);
    // swap(v,v2);
    // cout<<endl;
    // for(auto ele:v){
    //     cout<<ele<<" ";
    // }
    // for(auto ele:v2){
    //     cout<<ele<<" ";
    // }
    
    // pair <int, int> p;
    // p.first = 3;
    // p.second = 10;
    // int arr[] = {10,16,7,14,5,3,12,9};
    // int arr[] = {1,3,2,3,4,1,6,4,3};
    // countSort(arr,9);
    // for(int i=0;i<9;i++){
    //     cout<<arr[i]<<" ";
    // }
    
    int arr[] = {4,3,1,7,5,6,2};
    waveSort(arr,7);
    for(int i=0;i<7;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    // vector<pair<int, int>> v;
    // for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
    //     // pair<int, int> p;
    //     // p.first = arr[i];
    //     // p.second = i;
    //     v.push_back(make_pair(arr[i], i));
    // }
    // sort(v.begin(), v.end(), myCompare);
    // for(int i=0;i<v.size();i++){
    //     arr[v[i].second] = i;
    // }
    // for(int i=0;i<v.size();i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;

    return 0;
}