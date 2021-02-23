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
    Node *prev;
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

void printlistreverse(Node *head)
{
    while (head->next != NULL)
    {
        // cout<<head->data<<" ";
        head = head->next;
    }
    debug("lul", head->data);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->prev;
    }
    cout << endl;
}

void insert(struct Node **head, int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void Split(Node *head, Node **a, Node **b)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next and fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *a = head;
    *b = slow->next;
    slow->next = NULL;
}

Node *Merge(Node *a, Node *b)
{

    Node *result = NULL;

    if (!a)
    {
        return b;
    }
    if (!b)
    {
        return a;
    }
    if (a->data <= b->data)
    {
        result = a;
        result->next = Merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = Merge(a, b->next);
    }
    return result;
}

void mergesort(Node **head)
{

    if (!(*head) || !(*head)->next)
    {
        return;
    }
    Node *a;
    Node *b;
    Split(*head, &a, &b);

    mergesort(&a);
    mergesort(&b);

    *head = Merge(a, b);
}

void check_sum(Node *head, int sum)
{
    Node *start = head;
    Node *end = head;
    while (end->next != NULL)
    {
        end = end->next;
    }
    // debug("here ->", start->data, end->data);
    // cout<<endl;

    bool found = 0;
    while (start != end)
    {
        // debug("here again ->", start->data, end->data);
        // cout<<endl;
        if (start->next == end)
        {
            if ((start->data + end->data) == sum)
            {
                found = 1;
                cout << "Found ya 1 [ " << start->data << " ," << end->data << " ]" << endl;
            }
            break;
        }
        if ((start->data + end->data) == sum)
        {
            found = 1;
            cout << "Found ya 2 [ " << start->data << " ," << end->data << " ]" << endl;
            start = start->next;
            end = end->prev;
        }
        else if ((start->data + end->data) < sum)
        {
            cout << "one" << endl;
            start = start->next;
        }
        else
        {
            cout << "two" << endl;
            end = end->prev;
        }
        // cout<<"1"<<endl;
    }
    if (!found)
    {
        cout << "Bad luck mate!" << endl;
    }
}

void solve()
{
    Node *head = NULL;

    //
    // insert(&head, 1);
    // insert(&head, 2);
    // insert(&head, 3);
    // insert(&head, 4);
    // insert(&head, 5);
    // insert(&head, 6);
    // insert(&head, 7);
    // insert(&head, 8);
    // insert(&head, 9);

    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    cout << "Before sorting the linkedlist->" << endl;
    printlist(head);

    mergesort(&head);

    cout << "After sorting the linkedlist->" << endl;
    printlist(head);

    printlistreverse(head);

    int sum;
    cout << "Enter the sum you want" << endl;
    cin >> sum;

    check_sum(head, sum);
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
