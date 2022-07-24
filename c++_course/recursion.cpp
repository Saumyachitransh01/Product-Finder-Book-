#include <iostream>
using namespace std;

int firstocc(int arr[], int n, int i, int key)
{
    if (n == i)
    {
        return -1;
    }
    if (arr[i] == key)
        return i;

    return firstocc(arr, n, i + 1, key);
}
int lastocc(int arr[], int n, int i, int key)
{
    if (n == i)
    {
        return -1;
    }
    int rest = lastocc(arr, n, i + 1, key);
    if (rest != -1)
        return rest;

    if (arr[i] == key)
        return i;
    return -1;
}
void reverse(string s)
{
    if (s.length() == 0)
        return;

    string ros = s.substr(1);
    reverse(ros);
    cout << s[0];
}
void replacepi(string s)
{
    if (s.length() == 0)
        return;
    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replacepi(s.substr(2));
    }
    else
    {
        cout << s[0];
        replacepi(s.substr(1));
    }
}
void toi(int n, char src, char dest, char helper)
{
    if (n == 0)
        return;
    toi(n - 1, src, helper, dest);
    cout << "Move from " << src << " to " << dest << endl;
    toi(n - 1, helper, dest, src);
}
string removeDup(string s)
{
    if (s.length() == 0)
        return "";
    char ch = s[0];
    string ans = removeDup(s.substr(1));
    if (ch == ans[0])
        return ans;
    return (ch + ans);
}
string moveX(string s)
{
    if (s.length() == 0)
        return "";
    char ch = s[0];
    string ans = moveX(s.substr(1));
    if (ch == 'x')
        return ans + ch;
    return ch + ans;
}
void subseq(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    string ros = s.substr(1);
    subseq(ros, ans);
    subseq(ros, ans + s[0]);
}
void subsequ(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);
    subsequ(ros, ans);
    subsequ(ros, ans + ch);
    subsequ(ros, ans + to_string(code));
}
string keyPadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void keypad(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string code = keyPadArr[ch - '0'];
    string ros = s.substr(1);

    for (int i = 0; i < code.length(); i++)
    {
        keypad(ros, ans + code[i]);
    }
}
void permutation(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);
        permutation(ros, ans + ch);
    }
}
int countPath(int s, int e)
{
    if (s == e)
        return 1;

    if (s > e)
        return 0;

    int count = 0;
    for (int i = 1; i <= 6; i++)
        count += countPath(s + i, e);
    return count;
}
int countMaze(int n, int i, int j)
{
    if (i == n - 1 && j == n - 1)
        return 1;
    if (i >= n || j >= n)
        return 0;

    return countMaze(n, i + 1, j) + countMaze(n, i, j + 1);
}
int tiling(int n)
{
    if (n == 0 || n == 1)
        return n;
    return tiling(n - 1) + tiling(n - 2);
}
int pairing(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return n;
    return pairing(n - 1) + pairing(n - 2) * (n - 1);
}
int sack(int value[], int wt[], int n, int w)
{
    if (n == 0 || w == 0)
        return 0;

    if (wt[n - 1] > w)
        return sack(value, wt, n - 1, w);

    return max(sack(value, wt, n - 1, w - wt[n - 1]) + value[n - 1], sack(value, wt, n - 1, w));
}

int main()
{
    // int ar[] = {1,2,3,2,5,2,8};
    // cout<<firstocc(ar,6,0,2)<<" ";
    // cout<<lastocc(ar,6,0,2)<<endl;
    // reverse("SAUMYA");
    // replacepi("pipppiipipipi");
    // toi(3,'A','C','B');
    cout<<removeDup("aaaaabbbcccdddd");
    // cout<<moveX("aaxdxdrtxjihxxnnoi");
    // subsequ("AB","");
    // keypad("23","");
    // permutation("123", ""); //it's total of factorial of the number of digits
    // cout<<countPath(0, 3);
    // cout<<countMaze(3,0,0);
    // cout<<tiling(4);
    // cout<<pairing(4);
    // int wt[] = {10, 20, 30};
    // int value[] = {100, 50, 150};
    // int w = 50;
    // cout<<sack(value,wt,3,w);

    cout << endl;
}