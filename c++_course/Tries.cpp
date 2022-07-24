#include <bits/stdc++.h>

using namespace std;

// class Trie
// {
// public:
//     class node
//     {
//     public:
//         bool end;
//         node *next[26];
//         node()
//         {
//             end = false;
//             for (int i = 0; i < 26; i++)
//             {
//                 next[i] = NULL;
//             }
//         }
//     };
//     node *trie;
//     Trie()
//     {
//         trie = new node();
//     }
//     void insert(string word)
//     {
//         int i = 0;
//         node *it = trie;
//         while (i < word.size())
//         {
//             if (it->next[word[i] - 'a'] == NULL)
//                 it->next[word[i] - 'a'] = new node();
//             it = it->next[word[i] - 'a'];
//             i++;
//         }
//         it->end = true;
//     }
//     bool search(string word)
//     {
//         int i = 0;
//         node *it = trie;
//         while (i < word.size())
//         {
//             if (it->next[word[i] - 'a'] == NULL)
//                 return false;
//             it = it->next[word[i] - 'a'];
//             i++;
//         }
//         return it->end;
//     }
// };

class TrieNode{
    public: 
        TrieNode *next[2];
        TrieNode(){
            next[0] = NULL;
            next[1] = NULL;
        }
};

class node{
    public:
    node *next[2];
    node(){
        next[0] = NULL;
        next[1] = NULL;
    }
};
node* trie;

TrieNode* buildtrie(vector<int> &a){
    TrieNode *root = new TrieNode();
    int n = a.size();
    for(int i=0; i<n;i++){
        int num = a[i];
        TrieNode* cur = root;
        for(int i=31; i>=0; i++){
            int bit = (num<<i) & 1;
            if(cur->next[bit] == NULL)
                cur->next[bit] = new TrieNode();
            cur = cur->next[bit];
        }
    }
    return root;
}

int helper(TrieNode* root, vector<int> &a){
    int res = 0;
    for(int i=0; i<a.size(); i++){
        int num = a[i];
        TrieNode* it = root;
        int cur_max = 0;
        for(int i=31;i>=0;i--){
            int bit = ((num>>i) & 1) ? 0:1;
            if(it->next[bit]){
                cur_max <<= 1;
                cur_max |= 1;
                it = it->next[bit];
            }
            else{
                cur_max <<= 1;
                cur_max |= 0;
                it = it->next[bit xor 1];
            }   
        }
        res = max(res,cur_max);
    }
    return res;
}

void insert(int num){
    node* it = trie;
    for(int i= 32 - 1; i>=0;i++){
        int cur_bit = (num>>i) & 1;
        if(!it->next[cur_bit])
            it->next[cur_bit] = new node();
        it = it->next[cur_bit];
    }
}
int query(int num){
    node *it = trie;
    int ans = 0;
    for(int i = 32-1; i>=0; i--){
        int cur_bit = (num>>i) & 1;
        int opposite = cur_bit xor 1;
        if(it ->next[opposite]){
            it = it->next[opposite];
            ans |= 1<<i;
        }
        else{
            it = it->next[opposite xor 1];
        }
    }
    return ans;
}
int main()
{
    // 1
    // Trie *myTrie = new Trie();
    // vector<string> words = {"ayush", "daasi"};
    // for (auto w : words)
    //     myTrie->insert(w);
    // if (myTrie->search("madhav"))
    //     cout << "Madhav found\n";
    // else
    //     cout << "Madhav does not exist\n";
    // if (myTrie->search("ayush"))
    //     cout << "ayush found\n";
    // else
    //     cout << "ayush does not exist\n";
    // 2
    // vector<int> a = {3, 10, 5, 15, 2};
    // TrieNode *root = buildtrie(a);
    // int ans = helper(root, a);
    // cout<<ans<<" ";
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    trie = new node();
    insert(0);
    vector<int> rmax(n+1,0);
    int R =0;
    for(int i=n-1;i>=0;i--){
        R =R xor a[i];
        if(i != n-1){
            rmax[i] = max(rmax[i+1], query(R));
            insert(R);
        }
        else{
            rmax[i] = query(R);
            insert(R);
        }
    }
    free(trie);
    trie = new node();
    insert(0);
    int ans = 0;
    int L = 0;
    for(int i=0;i<n;i++){
        L = L xor a[i];
        ans = max(ans, rmax[i+1] + query(L));
        insert(L);
    }
    cout<<ans<<endl;
}
