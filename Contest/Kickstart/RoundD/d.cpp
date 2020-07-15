#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n,q;
   cin >> n >> q;
   vector<int> D(n);
   f(i,1,n){
      cin >> D[i];
   }
   while(q--){
      int s,k;
      cin >> s >> k;
      set<int> S;
      f(i,1,n+1) S.insert(i);
      int cur = s;
      vector<int> ans;
      while(S.size() != 1){
         auto k = S.find(cur);
         ans.pb(cur);
         if(k == S.begin()){
            k++;
            cur = *k;
            k--;
            S.erase(k);
         }else{
            k++;
            if(k == S.end()){
               k--;
               k--;
               cur = *k;
               k++;
               S.erase(k);
            }else{
               k--;
               k--;
               int prv = *k;
               k++;
               k++;
               int nxt = *k;
               k--;
               S.erase(k);
               if(D[prv] < D[nxt-1]){
                  cur = prv;
               }else{
                  cur = nxt;
               }
            }
         }
      }
      ans.pb(*S.begin());
      cout << ans[k-1] << ' ';
   }
   cout << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt){
      cout << "Case #" << i+1 << ": ";
      test();   
   }
   return 0;
} 