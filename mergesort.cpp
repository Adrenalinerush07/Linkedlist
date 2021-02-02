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
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void FrontBackSplit(Node *source, Node **frontRef, Node **backRef)
{
    Node *fast = source;
    Node *slow = source;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

Node *SortedMerge(Node *a, Node *b)
{
    Node *result = NULL;

    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }

    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}

void MergeSort(Node **head_ref)
{
    Node *head = *head_ref;
    Node *a;
    Node *b;

    // No nodes / single node
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    // dividing the linkedlist into two parts
    FrontBackSplit(head, &a, &b);

    // Recursively sort the sublist
    MergeSort(&a);
    MergeSort(&b);

    // head_ref jis chiz ka address store kiya hai(head) uska value
    *head_ref = SortedMerge(a, b);
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