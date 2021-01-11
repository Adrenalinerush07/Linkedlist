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
https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/ 



*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* prev=NULL;
    ListNode* itr=A;
    unordered_map<int,int> cnt;
    while(itr != NULL){
        if(!cnt[itr->val]){
            cnt[itr->val]++;
            if(prev==NULL){
                prev=A;
            }
            else{
                prev=prev->next;
            }
            prev->val=itr->val;
            itr=itr->next;
        }
        else{
            itr=itr->next;
        }
    }
    if(prev != itr){
        prev->next=NULL;    
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