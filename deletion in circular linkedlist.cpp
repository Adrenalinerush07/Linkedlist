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

https://www.geeksforgeeks.org/deletion-circular-linked-list/
*/

class Node
{
public:
    int data;
    Node *next;
};

/* Function to insert a node at the beginning of 
a Circular linked list */
void push(Node **head_ref, int data)
{
    // Create a new node and make head as next
    // of it.
    Node *ptr1 = new Node();
    ptr1->data = data;
    ptr1->next = *head_ref;

    /* If linked list is not NULL then set the 
    next of last node */
    if (*head_ref != NULL)
    {
        // Find the node before head and update
        // next of it.
        Node *temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; /*For the first node */

    *head_ref = ptr1;
}

void deleteNode(Node **head, int key)
{
    if (!*head)
    {
        return;
    }
    Node *cur = *head;
    Node *prev;

    while (cur != NULL)
    {
        if (cur->data == key)
        {
            break;
        }
        prev = cur;
        cur = cur->next;
    }

    Node *tail = *head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    if (cur == *head)
    {
        if (cur->next == NULL)
        {
            *head == NULL;
            return;
        }
        *head = (*head)->next;
        tail->next = *head;
    }

    if (cur == tail)
    {
        prev->next = *head;
        return;
    }

    prev->next = cur->next;
    return;
}

void solve()
{
    Node *head = NULL;

    push(&head, 2);
    push(&head, 5);
    push(&head, 7);
    push(&head, 8);
    push(&head, 10);

    deleteNode(&head, 7);
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