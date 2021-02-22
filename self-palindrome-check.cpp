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

void printlist(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void push(Node **head, int val)
{
    Node *n = new Node;
    n->data = val;
    n->next = *head;
    *head = n;
}

Node *reverse(Node *head)
{
    Node *next = NULL;
    Node *prev = NULL;
    Node *cur = head;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

bool checkPalindrome(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next and fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *it2 = reverse(slow->next);
    cout << slow->data << endl;

    debug(head->data, it2->data);

    while (it2 != NULL)
    {
        if (head->data != it2->data)
        {
            return 0;
        }
        head = head->next;
        it2 = it2->next;
    }

    return 1;
}

void solve()
{
    Node *head = NULL;

    // push(&head, 1);
    // push(&head, 2);
    // push(&head, 3);
    // push(&head, 4);
    // push(&head, 5);
    // push(&head, 6);
    // push(&head, 7);
    // push(&head, 8);
    // push(&head, 9);

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    // push(&head, 7);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printlist(head);

    if (checkPalindrome(head))
    {
        cout << "Yes it is a fooking Palindrome!";
    }
    else
    {
        cout << "No luck eh!";
    }
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tt;
    tt = 1;
    // cin>>tt;
    for (int t = 1; t <= tt; t++)
    {
        solve();
    }
}
