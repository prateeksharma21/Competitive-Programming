#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;
 
int ans;

void solve(vector<int> R,vector<int> G,vector<int> B){
   for(auto &e : R){
      {
         auto k1 = lower_bound(all(G),e);
         if(k1 == G.end()) k1--;
         if(k1 == G.begin()){
            auto k2 = lower_bound(all(B),*k1);
            if(k2 == B.end()) k2--;
            if(k2 == B.begin()){
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
            }else{
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
               k2--;
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
            }
         }else{
            auto k2 = lower_bound(all(B),*k1);
            if(k2 == B.end()) k2--;
            if(k2 == B.begin()){
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
            }else{
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
               k2--;
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
            }
            k1--;
            k2 = lower_bound(all(B),*k1);
            if(k2 == B.end()) k2--;
            if(k2 == B.begin()){
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
            }else{
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
               k2--;
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
            }
         }
      }
      {
         auto k1 = lower_bound(all(B),e);
         if(k1 == B.end()) k1--;
         if(k1 == B.begin()){
            auto k2 = lower_bound(all(G),*k1);
            if(k2 == G.end()) k2--;
            if(k2 == G.begin()){
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
            }else{
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
               k2--;
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
            }
         }else{
            auto k2 = lower_bound(all(G),*k1);
            if(k2 == G.end()) k2--;
            if(k2 == G.begin()){
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
            }else{
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
               k2--;
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
            }
            k1--;
            k2 = lower_bound(all(G),*k1);
            if(k2 == G.end()) k2--;
            if(k2 == G.begin()){
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
            }else{
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
               k2--;
               ans = min(ans,(e-*k1)*(e-*k1)+(e-*k2)*(e-*k2)+(*k1-*k2)*(*k1-*k2));
            }
         }  
      }
   }  
}

void test(){
   int nr,ng,nb;
   cin >> nr >> ng >> nb;
   vector<int> R(nr),G(ng),B(nb);
   for(auto &e : R){
      cin >> e;
   }
   for(auto &e : G){
      cin >> e;
   }
   for(auto &e : B){
      cin >> e;
   }
   sort(all(R));
   sort(all(G));
   sort(all(B));
   ans = LLONG_MAX;
   solve(R,G,B);
   solve(G,R,B);
   solve(B,R,G);
   assert(ans!=LLONG_MAX);
   cout << ans << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}