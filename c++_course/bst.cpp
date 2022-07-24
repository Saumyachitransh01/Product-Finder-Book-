#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node *insertBST(node *root, int val)
{
    if (root == NULL)
        return new node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

node *searchBST(node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    if (root->data > key)
        return searchBST(root->left, key);
    return searchBST(root->right, key);
}

node *inorderSucc(node *root)
{
    node *curr = root;
    while (curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}

node *deleteBST(node *root, int key)
{

    if (key < root->data)
        root->left = deleteBST(root->left, key);
    else if (key > root->data)
        root->right = deleteBST(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

node *constructBST(int preorder[], int *idx, int key, int min, int max, int n)
{
    if (*idx >= n)
        return nullptr;
    node *root = NULL;
    if (key > min && key < max)
    {
        root = new node(key);
        *idx = *idx + 1;
        if (*idx < n)
            root->left = constructBST(preorder, idx, preorder[*idx], min, key, n);
        if (*idx < n)
            root->right = constructBST(preorder, idx, preorder[*idx], key, max, n);
    }
    return root;
}

bool isBST(node *root, node *min = nullptr, node *max = nullptr)
{
    if (root == NULL)
        return true;
    if (min != NULL && root->data <= min->data)
        return false;
    if (max != NULL && root->data >= max->data)
        return false;
    bool lefty = isBST(root->left, min, root);
    bool righty = isBST(root->right, root, max);

    return lefty and righty;
}

int isBSTUtil(struct node *node, int min, int max)
{
    if (node == NULL)
        return 1;
    if (node->data > max || node->data < min)
        return 0;
    return isBSTUtil(node->left, min, node->data - 1) && isBSTUtil(node->right, node->data + 1, max);
}

int isBST(struct node *node){
  return (isBSTUtil(node, INT_MIN, INT_MAX));
}

// bool isBST(struct node *root)
// {
//     static struct node *prev = NULL;
//     if (root)
//     {
//         if (!isBST(root->left))
//             return false;
//         if (prev != NULL && root->data <= prev->data)
//             return false;
//         prev = root;
//         return isBST(root->right);
//     }
//     return true;
// }

void printPreorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

node *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
        return nullptr;
    int mid = (start + end) / 2;
    node *root = new node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

vector<node *> constructTree(int start, int end)
{
    vector<node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<node *> leftSubtree = constructTree(start, i - 1);
        vector<node *> rightSubtree = constructTree(i + 1, end);
        for (int j = 0; j < leftSubtree.size(); j++)
        {
            node *left = leftSubtree[j];
            for (int k = 0; k < rightSubtree.size(); k++)
            {
                node *right = rightSubtree[k];
                node *no = new node(i);
                no->left = left;
                no->right = right;
                trees.push_back(no);
            }
        }
    }
    return trees;
}

void zigzag(node *root)
{
    if (root == NULL)
        return;
    stack<node *> curr;
    stack<node *> next;
    bool leftToRight = true;
    curr.push(root);
    while (!curr.empty())
    {
        node *temp = curr.top();
        curr.pop();
        if (temp)
        {
            cout << temp->data << " ";

            if (leftToRight)
            {
                if (temp->left)
                    next.push(temp->left);
                if (temp->right)
                    next.push(temp->right);
            }
            else
            {
                if (temp->right)
                    next.push(temp->right);
                if (temp->left)
                    next.push(temp->left);
            }
        }
        if (curr.empty())
        {
            leftToRight = !leftToRight;
            swap(curr, next);
        }
    }
}

bool isIdentical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    else if (root1 == NULL || root2 == NULL)
        return false;
    else
    {
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);
        if (cond1 && cond2 && cond3)
            return true;
        return false;
    }
}

struct info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

info largestBST(node *root)
{
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};

    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};

    info leftInfo = largestBST(root->left);
    info rightInfo = largestBST(root->right);
    info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);
    if (leftInfo.isBST && rightInfo.isBST && (leftInfo.max < root->data) && (rightInfo.min > root->data))
    {
        curr.min = min(leftInfo.min, root->data);
        curr.max - max(rightInfo.max, root->data);
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}

void calcPointer(node *root, node **first, node **mid, node **last, node **prev)
{
    if (root == NULL)
        return;
    calcPointer(root->left, first, mid, last, prev);
    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcPointer(root->right, first, mid, last, prev);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void restoreBST(node *root)
{
    node *first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calcPointer(root, &first, &mid, &last, &prev);
    if (first && last)
        swap(&(first->data), &(last->data));
    else if (first && mid)
        swap(&(first->data), &(mid->data));
}

bool isFeasable(int mid, int arr[], int n, int k)
{
    int pos = arr[0], element = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            element++;
            if (element == k)
                return true;
        }
    }
    return false;
}

bool isPossible(int arr[], int n, int m, int min)
{
    int student = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
            return false;
        if (sum + arr[i] > min)
        {
            student++;
            sum = arr[i];
            if (student > m)
                return false;
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}

int allocateMin(int arr[], int n, int m)
{
    int sum = 0;
    if (n < m)
        return -1;

    for (int i = 0; i < n; i++)
        sum += arr[i];
    int start = 0, end = sum, ans = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int largestDistance(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int result = -1;
    int left = 1, right = arr[n - 1];
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isFeasable(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
            right = mid;
    }
    return result;
}

int findFeasible(int boards[], int n, int limit)
{
    int sum = 0, painter = 1;
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
        if (sum > limit)
        {
            sum = boards[i];
            painter++;
        }
    }
    return painter;
}

int painters(int boards[], int n, int m)
{
    int totalLength = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        k = max(k, boards[i]);
        totalLength += boards[i];
    }
    int low = k, high = totalLength;
    while (low < high)
    {
        int mid = (low + high) / 2;
        int painter = findFeasible(boards, n, mid);
        if (painter <= m)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int searchInRotation(int arr[], int key, int left, int right)
{
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (arr[mid] == key)
        return mid;
    if (arr[left] <= arr[mid])
    {
        if (key >= arr[left] && key <= arr[mid])
        {
            return searchInRotation(arr, key, left, mid - 1);
        }
        return searchInRotation(arr, key, mid + 1, right);
    }
    if (key >= arr[mid] && key <= arr[right])
        return searchInRotation(arr, key, mid + 1, right);

    return searchInRotation(arr, key, left, mid - 1);
}

int findPeak(int arr[], int low, int high, int n)
{
    int mid = low + (high - low) / 2;
    if ((mid == 0 || arr[mid + 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        return mid;
    else if (mid > 0 && arr[mid - 1] > arr[mid])
        return findPeak(arr, low, mid - 1, n);
    else
        return findPeak(arr, mid + 1, high, n);
}

void maxSubarray(int arr[], int n, int k, int x)
{
    int sum = 0, ans;
    for (int i = 0; i < k; i++)
        sum += arr[i];

    if (sum < x)
        ans = sum;
    for (int i = 0; i < n; i++)
    {
        sum -= arr[i - k];
        sum += arr[i];
        if (sum < x)
            ans = max(ans, sum);
    }
    cout << ans << " is the max subarray." << endl;
}

int smallestSum(int arr[], int n, int x)
{
    int sum = 0, minLength = n + 1, start = 0, end = 0;
    while (end < n)
    {
        while (sum <= x && end < n)
            sum += arr[end++];
        while (sum > x && start < n)
        {
            if (end - start < minLength)
                minLength = end - start;
            sum -= arr[start++];
        }
    }
    return minLength;
}

void computeNumber(vector<int> arr, int k)
{
    pair<int, int> ans;
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];

    bool found = false;
    if (sum % 3 == 0)
    {
        ans = make_pair(0, k - 1);
        found = true;
    }
    for (int j = k; j < arr.size(); j++)
    {
        if (found)
            break;
        sum = sum + arr[j] - arr[j - k];
        if (sum % 3 == 0)
        {
            ans = make_pair(j - k + 1, j);
            found = true;
        }
    }
    if (!found)
        ans = make_pair(-1, 0);
    if (ans.first == -1)
        cout << "No such subarray exists" << endl;
    else
    {
        for (int i = ans.first; i <= ans.second; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int main()
{
    node *root = new node(6);
    root->left = new node(9);
    root->right = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->right->right = new node(13);
    // root1->left->right = new node(5);
    // root1->right->left = new node(6);
    // root1->right->right = new node(7);
    // node* root2 = new node(1);
    // root2->left = new node(2);
    // root2->right = new node(3);
    // root2->left->left = new node(4);
    // root2->left->right = new node(5);
    // root2->right->left = new node(6);
    // root2->right->right = new node(7);
    // if(searchBST(root, 5) == NULL)
    //     cout<<"Key doesn't exist";
    // else
    // cout<<"Key exists";
    // inorder(root);
    // root=deleteBST(root, 2);
    // cout<<endl;
    // inorder(root);
    // int preorder[] = {10,2,1,13,11};
    // int n=5;
    // int idx = 0;
    // constructBST(preorder, &idx, preorder[0], INT_MIN, INT_MAX, n);
    // printPreorder(root);
    // cout<<isBST(root, nullptr, nullptr);
    // int arr[] = {10,20,30,40,50};
    // node* root = sortedArrayToBST(arr,0,4);
    // vector<node*> totalTrees = constructTree(1,3);
    // for(int i=0;i<totalTrees.size();i++){
    //     cout<<(i+1)<<" : ";
    //     printPreorder(totalTrees[i]);
    //     cout<<endl;
    // }
    // zigzag(root);
    // if(isIdentical(root,root2))
    //     cout<<"BSTs are Identical"<<endl;
    // else cout<<"BSTs NOT Identical";
    // cout<<"Largest BST in BT: "<<largestBST(root).ans;
    // inorder(root);
    // restoreBST(root);
    // cout<<endl;
    // inorder(root);
    // int arr[]  = {12,34,67,90};
    // int n=4, m=2;
    // cout<<"Minimum pages is: "<<allocateMin(arr, n, m)<<endl;
    // int arr[] = {1,4,45,6,10,19};
    // int k=3, x=51, n=6;
    // int idx = searchInRotation(arr, key, 0, n-1);
    // cout<<"Peak element index : "<<findPeak(arr, 0, n-1, n)<<endl;
    // if(idx == -1)
    //     cout<<"Key doesn't exist";
    // else
    //     cout<<"Key exist at "<<idx<<endl;
    // maxSubarray(arr,n,k,x);
    // int minLength = smallestSum(arr,n,x);
    // if(minLength == n+1)
    //     cout<<"No such subarray exist"<<endl;
    // else
    //     cout<<" Smallest length subarray is: "<<minLength<<endl;
    vector<int> arr = {84, 23, 55, 12, 56, 82};
    int k = 3;
    computeNumber(arr, k);
    return 0;
}
