#include<bits/stdc++.h>
using namespace std;
#define int long long

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
// void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif 

const int N=2e5+4;
const int mod=1e9+7;

/*

ref = https://www.geeksforgeeks.org/find-kth-node-from-middle-towards-head-of-a-linked-list/

/*
Interview-bit soln

int Solution::solve(ListNode* A, int B) {
    int count=0;
    ListNode* current=A;
    while(current != NULL){
        count++;
        current = current->next;
    }
    int req=((count/2)+1)-B;
    if(req<=0){
        return -1;
    }
    current=A;
    count=1;
    while(current != NULL){
        if(count==req){
            return (current->val);
        }
        count++;
        current=current->next;
    }
    return -1;
}

*/
*/

// Linked list node
struct Node{
    int data;
    Node* next;
};

// push function with takes reference to (pointer to pointer) to
// head and pushes new node in the front of the list
void push(Node** head_ref, int new_data){
    Node* new_node = new Node;
    new_node-> data = new_data;
    // add krne ke pehle jo first node hai uska address ha (*head_ref)
    new_node->next = (*head_ref);
    (*head_ref)=new_node;
}
// count number of nodes
int count(struct Node* head){
    int count=0;
    Node* current=head;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}
// function to get the ans
int sol(Node* head_ref, int k){
    int n=count(head_ref);
    int req=((n/2)+1)-k;
    if(req<=0){
        return -1;
    }
    Node* current=head_ref;
    int count=1;
    while(current != NULL){
        if(count==req){
            return (current->data);
        }
        count++;
        current=current->next;
    }
    return -1;
}
void solve(){
    Node* head = NULL; 
    int k = 2; 
  
    // create linked list 
    // 1->2->3->4->5->6->7 
    push(&head, 7); 
    push(&head, 6); 
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 
  
    cout << sol(head, 2); 
}

int32_t main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tt; 
    tt=1;
    cin>>tt;
    for(int t=1;t<=tt;t++){
        solve();
    }
} 