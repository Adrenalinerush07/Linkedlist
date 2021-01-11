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
https://www.interviewbit.com/problems/intersection-of-linked-lists/ 



*/
// Method 1- 
int length(ListNode* A) {
    ListNode* itr=A;
    int count=0;
    while(itr != NULL){
        count++;
        itr=itr->next;
    }
    return count;
}
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int n=length(A);
    int m=length(B);
    // if(n>m){
        
    // }
    set<ListNode* > location;
    ListNode* head=B;
    while(head != NULL){
        location.insert(head);
        head=head->next;
    }
    while(A != NULL){
        if(location.find(A) != location.end()){
            return A;
        }
        A=A->next;
    }
    return NULL;
}

// Method 2
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int a = length(A);
    int b = length(B);
    int d = b-a;
    if(a > b){
        //swap the 2 lists 
        ListNode *temp = A;
        A = B;
        B = temp;
        d = a-b;
    }
    
    for(int i = 0; i<d; i++){
        B = B->next;
    }
    //both A and B are now equidistant from merge point
   
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