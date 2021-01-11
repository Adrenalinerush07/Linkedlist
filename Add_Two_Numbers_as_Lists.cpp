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

https://www.interviewbit.com/problems/add-two-numbers-as-lists/ 


*/

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* currentA=A;
    ListNode* currentB=B;
    ListNode* head;
    ListNode* current;
    bool init=1;
    int carry=0;
    
    while (currentA != nullptr || currentB != nullptr || carry !=0){
        int sum=0;
        int dig=0;
        if(currentA != nullptr){
           sum += currentA->val;
           currentA = currentA->next;
        }
        
        if(currentB != nullptr){
           sum += currentB->val;
           currentB= currentB->next;
        }
        
        sum += carry; 
        carry = sum/10;
        dig = sum%10;
        
        if(init){
          current = new ListNode(dig);        
          head=current; 
          init=0;
        }
        else{
            current->next = new ListNode(dig);
            current=current->next;
        }
    }
    
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