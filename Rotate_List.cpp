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
https://www.interviewbit.com/problems/rotate-list/ 



*/

int length(ListNode* A){
    int count=0;
    ListNode* it=A;
    while(it != NULL){
        count++;
        it=it->next;
    }
    return count;
}
ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode* itr=A;
    ListNode* prev=A;
    int len=length(A);
    B=B%len;
    if(!B){
        return A;
    }
    if(len==1){
        return A;
    }
    int count=len-B;
    // cout<<"count ->"<<count<<endl;
    while(itr != NULL and count){
        count--;
        prev=itr;
        itr=itr->next;
    }
    prev->next=NULL;
    ListNode* tail;
    ListNode* head=itr;
    while(itr != NULL){
        tail=itr;
        itr=itr->next;
    }
    tail->next=A;
    return head;
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