#include <bits/stdc++.h>
using namespace std;
#define int long long

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
// void __print(long long x) {cerr << x;}
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

const int N = 2e5 + 4;
const int mod = 1e9 + 7;

/*



*/

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *helper(Node *head)
{
    Node *res = head;
    Node *temp, *prev = NULL;
    int carry = 1, sum = 0;
    while (head != NULL)
    {
        sum = carry + head->data;
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        head->data = sum;

        temp = head;
        head = head->next;
    }
    if (carry > 0)
    {
        temp->next = newNode(carry);
    }
    return res;
}

Node *addOne(Node *head)
{
    head = reverse(head);
    head = helper(head);
    return reverse(head);
}

void solve()
{
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
        solve();
    }
}