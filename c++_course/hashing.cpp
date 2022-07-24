#include<bits/stdc++.h>
#include <climits>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;

    Node(int val){
        key = val;
        left = NULL;
        right = NULL;
    }
};

void countFreq(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    map<int, int> freq;
    for(int i=0;i<n;i++)
        freq[a[i]]++;
    map<int, int> :: iterator it;
    for(it=freq.begin(); it!=freq.end(); it++)
        cout<<it->first<<" "<<it->second<<endl;
}

void getVerticalOrder(Node* root, int hdis, map<int, vector<int>> &m){
    if(root == NULL)
        return;
    m[hdis].push_back(root->key);
    getVerticalOrder(root->left, hdis-1, m);
    getVerticalOrder(root->right, hdis+1, m);
}

void helper(int r, int c, vector<vector<char>> &a, map<pair<int, int>, map<int, int>> &mp, vector<map<int, int>> row, vector<map<int, int>> col){
    if(r==9){
        for(auto it : a){
            for(auto i : it)
                cout<<i<<" ";
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    if(c == 9){
        helper(r+1, 0,a,mp,row, col);
        return;
    }
    if(a[r][c] != '.'){
        helper(r, c+1, a, mp, row, col);
        return; 
    }
    for(int i=1; i<=9;i++){
        int rw = r/3, cl = c/3;
        if(!mp[{rw, cl}][i] and !row[r][i] and !col[c][i]){
            mp[{rw, cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            a[r][c] = i + '0';
            helper(r, c+1, a,mp, row, col);
            mp[{rw, cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            a[r][c] = '.';
        }
    }
}

void solveSudoku(vector<vector<char>> &a){
    map<pair<int, int>, map<int, int>> mp;
    vector<map<int, int>> row(9);
    vector<map<int, int>> col(9);
    for(int i=0; i<9;i++){
        for(int j=0;j<9;j++){
            if(a[i][j] != '.'){
                mp[{i/3, j/3}][a[i][j]-'0'] = 1;
                row[i][a[i][j]- '0'] = 1;
                col[j][a[i][j]- '0'] = 1;
            }
        }
    }
    helper(0, 0, a, mp, row, col);
}

signed main(){
    // Node* root  = new Node(10);
    // root->left = new Node(7);
    // root->right = new Node(4);
    // root->left->left = new Node(3);
    // root->left->right = new Node(11);
    // root->right->left = new Node(14);
    // root->right->right = new Node(6);
    // map<int, vector<int>> mp;
    // int hdis = 0;
    // getVerticalOrder(root, hdis, mp);
    // map<int, vector<int>> :: iterator it;
    // for(it=mp.begin();it!=mp.end();it++){
    //     for(int i=0;i<(it->second).size();i++)
    //         cout<<(it->second)[i]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;
    // int n;
    // cin>>n;
    // vector<int> a(n);
    // for(int i=0;i<n;i++)
    //     cin>>a[i];
    // map<int,int> cnt;
    // int prefSum=0;
    // for(int i=0;i<n;i++){
    //     prefSum += a[i];
    //     cnt[prefSum]++;
    // }
    // int ans = 0;
    // map<int,int> :: iterator it;
    // for(it = cnt.begin();it!=cnt.end();it++){
    //     int c = it->second;
    //     ans += (c*(c-1))/2;
    //     if(it->first == 0)
    //         ans += it->second;
    // }
    // cout<<ans<<endl;
    // int n, k;
    // cin>>n>>k;
    // vector<int> a(n);
    // for(int i=0;i<n;i++)
    //     cin>>a[i];
    // int s=0, ans = INT_MAX;
    // for(int i=0;i<k; i++){
    //     s += a[i];
    // }
    // cout<<s<<" ";
    // ans = min(ans, s);
    // // sliding window
    // for(int i=1;i<=n-k;i++){
    //     s -= a[i-1];
    //     s += a[i+k-1];
    //     ans = min(ans, s); 
    //     cout<<s<<" "; 
    // }
    // cout<<endl<<ans<<endl;   
    // int n, k;
    // cin>>n>>k;
    // vector<int> a(n);
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    // map<int, int> freq;
    // for(int i=0; i<n; i++){
    //     int present = freq.size();
    //     if(freq[a[i]] == 0 && present == k)
    //         break;
    //     freq[a[i]]++;
    // }
    // vector<pair<int, int>> ans;
    // map<int, int> :: iterator it;
    // for(it=freq.begin(); it!=freq.end(); it++){
    //     if(it->second != 0){
    //         pair<int, int> p;
    //         p.first = it->second;
    //         p.second = it->first;
    //         ans.push_back(p);
    //     }          
    // }
    // sort(ans.begin(), ans.end(), greater<pair<int, int>>());
    // vector<pair<int, int>> :: iterator it1;
    // for(it1 = ans.begin(); it1!= ans.end();it1++){
    //     cout<<it1->second<<" "<<it1->first<<"\n";
    // }

    vector<vector<char>> sudoku = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };
    solveSudoku(sudoku);
    return 0;
}
