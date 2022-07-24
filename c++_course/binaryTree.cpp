#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    public:
    node(int val){
        data = val;
        left = NULL;
        right=NULL;
    }
};

void preorder(struct node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct node* root){
    if(root==nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int search(int inorder[], int start, int end, int val){
    for(int i=start;i<=end;i++)
        if(inorder[i]==val)
            return i;
    return -1;
}
node* buildTree(int preorder[], int inorder[], int start, int end){
    static int idx=0;
    if(start>end)
        return NULL;
    
    int curr = preorder[idx];
    idx++;
    node* n = new node(curr);
    if(start==end)
        return n;

    int pos = search(inorder, start, end, curr);
    n->left = buildTree(preorder, inorder, start, pos-1);
    n->right = buildTree(preorder, inorder, pos+1, end);
    return n;
}
node* treeBuild(int postorder[], int inorder[], int start, int end){
    static int idx = 4;
    if(start>end)
        return nullptr;
    int val = postorder[idx];
    idx--;
    node* curr = new node(val);
    if(start == end)
        return curr;
    int pos = search(inorder, start, end, val);
    curr->right = treeBuild(postorder, inorder, pos+1,end);
    curr->left = treeBuild(postorder, inorder, start, pos-1);

    return curr;
}

void inorderPrint(node* root){
    if(root==nullptr)
        return;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

void printLevel(node* root){
    if(root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;
    while(!q.empty()){
        node* n = q.front();
        q.pop();
        if(n != NULL){
            cout<<n->data<<" ";
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
        else if(!q.empty())
            q.push(NULL);
    }
}

int sumAtK(node* root, int k){
    if(root == NULL)
        return -1;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;
    while(!q.empty()){
        node* n = q.front();
        q.pop();
        if(n != NULL){
            if(level==k)
                sum += n->data;
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
 }
int countNodes(node* root){
    if(root ==NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
int sumNodes(node* root){
    if(root ==NULL)
        return 0;
    return sumNodes(root->left)+sumNodes(root->right)+root->data;
}

int calHeight(node* root){
    if(root==NULL)
        return 0;
    int l = calHeight(root->left);
    int r = calHeight(root->right);

    return max(l,r) + 1;
}

int diameter(node* root){
    if(root ==NULL)
        return 0;
    int lh = calHeight(root->left);
    int rh = calHeight(root->right);
    int curr = lh + rh + 1;
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    return max(curr, max(ld,rd));
} // n^3 complexity
int calDia(node* root, int* height){
    if(root ==NULL){
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ld = calDia(root->left, &lh);
    int rd = calDia(root->right, &rh);
    int curr = lh + rh +1;
    *height = max(lh, rh) + 1;
    return max(curr, max(ld,rd));
}
// n^2 complexity

void sumReplace(node* root){
    if(root ==  NULL)
        return;
    
    sumReplace(root->left);
    sumReplace(root->right);
    if(root->left != NULL)
        root->data += root->left->data;
    if(root->right != NULL)
        root->data += root->right->data;
}

bool balanced(node* root){
    if(root==NULL)
        return true;
    if(balanced(root->left) == false)
        return false;
    if(balanced(root->right) == false)
        return false;
    int lh = calHeight(root->left);
    int rh = calHeight(root->right);
    if(abs(lh-rh)<=1)
        return true;
    else  return false;
}

bool isBalanced(node* root, int*height){
    if(root == NULL)
        return true;
    int lh=0,rh=0;
    if(isBalanced(root->left, &lh) == false)
        return false;
    if(isBalanced(root->right, &rh) == false)
        return false;
    *height != max(lh,rh) + 1;
    if(abs(lh-rh) <=1)
        return true;
    else return false;
}

void rightView(node* root){
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n;i++){
            node* curr = q.front();
            q.pop();
            if(i==n-1)
                cout<<curr->data<<" ";
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
    }
}

void leftView(node* root){
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n;i++){
            node* curr = q.front();
            q.pop();
            if(i==0)
                cout<<curr->data<<" ";
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
    }
}

node* LCA(node* root, int n1, int n2){
    if(root == NULL)
        return NULL;
    if(root->data == n1 || root->data == n2)
        return root;
    node* left = LCA(root->left, n1, n2);
    node* right  = LCA(root->right, n1, n2);
    if(left != NULL && right != NULL)
        return root;
    if(left == NULL && right == NULL)
        return NULL;
    if(left!=NULL)
        return LCA(root->left, n1,n2);
    return LCA(root->right, n1, n2);   
}

int findDist(node* root, int k, int dist){
    if(root==NULL)
        return -1;
    if(root->data == k)
        return dist;
    int left = findDist(root->left, k ,dist+1);
    if(left != -1)
        return left;
    
    return findDist(root->right, k, dist+1);
}

int distNodes(node* root, int n1, int n2){
    node* lca = LCA(root, n1, n2);
    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);
    return d1+d2;
}

void flatten(node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if(root->left != NULL){
        flatten(root->left);

        node* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        node* t = root->right;
        while(t->right != NULL)
            t = t->right;
        t->right = temp;
    }
    flatten(root->right);
}

void printSubtree(node* root, int k){
    if(root == NULL || k<0)
        return;
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printSubtree(root->left, k-1);
    printSubtree(root->right, k-1);
}

int printNodes(node* root, node* target, int k){
    if(root == NULL)
        return -1;
    if(root == target){
        printSubtree(root, k);
        return 0;
    }
    int dl = printNodes(root->left,target , k);
    if(dl != -1){
        if(dl + 1 == k)
            cout<<root->data<<" ";
        else
            printSubtree(root->right, k-dl-2);
        return 1 + dl;
    } 
    int dr = printNodes(root->left,target, k);
    if(dr != -1){
        if(dr + 1 == k)
            cout<<root->data<<" ";
        else
            printSubtree(root->left, k-dr-2);
        return 1 + dr;
    }   
    return -1;    
}

bool getPath(node* root, int key, vector<int> &path){
    if(root == NULL)
        return false;
    
    path.push_back(root->data);
    if(root->data == key){
        return true;
    }
    if(getPath(root->left, key, path) || getPath(root->right, key, path))
        return true;
    path.pop_back();
    return false;
}

int lca(node* root, int n1, int n2){
    vector<int> path1, path2;
    if(!getPath(root, n1, path1) || !getPath(root, n2, path2))
        return -1;
    int pc;
    for(pc = 0; pc<path1.size() && path2.size();pc++){
        if(path1[pc] != path2[pc])
            break;
    }
    return path1[pc-1];
}

node* LCA2(node* root, int n1, int n2){
    if(root == NULL)
        return NULL;
    if(root->data == n1 || root->data == n2)
        return root;
    node* leftLCA = LCA2(root->left, n2, n1);
    node* rightLCA = LCA2(root->right, n2, n1);
    if(leftLCA && rightLCA)
        return root;
    if(leftLCA != nullptr)
        return leftLCA;
    return rightLCA;
}   

int maxPathUtil(node* root, int &ans){
    if(root == NULL)
        return 0;
    int left = maxPathUtil(root->left, ans);
    int right = maxPathUtil(root->right, ans);
    int nodeMax = max(max(root->data, root->data + left+right), max(root->data+left, root->data+right));
    ans = max(ans, nodeMax);
    int singlePath = max(root->data, max(root->data+left, root->data+right));
    return singlePath;
}

int maxPath(node* root){
    int ans = INT_MIN;
    maxPathUtil(root, ans);
    return ans;
}

int catalan(int n){
    if(n <= 1){
        return 1;
    }
    int res = 0;
    for(int i=0; i<n; i++){
        res+= catalan(i)*catalan(n-i-1);
    }
    return res;
}

int main(){
    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);
    // root->right->right = new node(7);
    // node* root2 = new node(1);
    // root2->left = new node(2);
    // root2->left->left = new node(3);
    // int n1=7, n2 = 6;
    // node* lc = LCA2(root, n1, n2);
    // preorder(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;
    // int preorder[] = {1, 2, 4, 3, 5};
    // int inorder[] = {4,2,1,5,3};
    // int postorder[] = {4,2,5,3,1};

    // node* root = treeBuild(postorder,inorder,0,4);
    // inorderPrint(root);
    // cout<<endl;
    // cout<<calDia(root, &height)<<endl;
    // preorder(root);
    // cout<<endl;
    // sumReplace(root);
    // preorder(root);
    // cout<<endl;
    // int height = 0;
    // if(isBalanced(root2, &height))
    //     cout<<"Balanced Tree"<<endl;
    // else cout<<"Not balanced"<<endl;
    // cout<<distNodes(root, 4, 5)<<endl;
    // flatten(root);
    // inorderPrint(root);  
    // printNodes(root, root->left, 1);
    // if(lc == NULL)
    //     cout<<"LCA doesn't exist"<<endl;
    // else    cout<<"LCA: "<<lc->data<<endl;
    // cout<<maxPath(root)<<endl;
    
    for(int i=0;i<10;i++){
        cout<<catalan(i)<<" ";
    }
    cout<<endl;
    return 0;
}