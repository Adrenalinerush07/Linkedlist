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
https://www.geeksforgeeks.org/reverse-alternate-k-nodes-in-a-singly-linked-list/ 
https://www.interviewbit.com/problems/reverse-alternate-k-nodes/ 

take exmp
create a list 1->2->3->4->5...... ->20 
k=3

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// method 1 => by recursive call
ListNode* sol(ListNode* head, int k){
    ListNode* current=head;
    ListNode* prev=NULL;
    ListNode* next=NULL;
    int count=0;

    while(current != NULL and count<k){
        // pehle next ko store kr
        next=current->next;
        // cur ko pichle wale se jod
        current->next=prev;
        // agle iteration ka preparation
        prev=current;
        current=next;
        count++;
    }

    // head 1 pe aa chuka hoga (3, 2, 1, ) tou 1 ko 4 se connect krna hoga
    if(head != NULL){
        head->next=current;
    }

    // 4 tou ek count ho chuka ha baki k-1 elements skip kr
    count=0;
    while(count<k-1 and current != NULL){
        current=current->next;
        count++;
    }

    // ye first 2*k elements jo process hua woh apna head return krega
    // uske tarak aage ke 2*k elements ka hard hamlog ko milega recursive call se
    // tou current jo hai (present 2*k elements ka last element) usko returned head se jod dena ha
    if(current != NULL){
        current->next=sol(current->next, k);
    }

    // prev mein head hota ha (refer reverse of linked list)
    return prev;
}

// method 2 => by stack method
ListNode* Solution::solve(ListNode* A, int B) {
    ListNode* itr=A;
    ListNode* prev=A;
    stack<int> reverse;
    bool doreverse = 1;
    int i=1;
    while(itr != NULL){
        if(i%B == 0){
            reverse.push(itr->val);
            if(doreverse){
                while(reverse.size()){
                    prev->val=reverse.top();
                    reverse.pop();
                    prev=prev->next;
                }
            }
            else{
                while(reverse.size()){
                    reverse.pop();
                }  
                prev=itr->next;
            }
            doreverse^=1;
        }
        else{
            reverse.push(itr->val);
        }
        itr=itr->next;
        i++;
    }
    return A;
}

void solve(){
    
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