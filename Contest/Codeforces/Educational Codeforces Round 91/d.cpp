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
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin >> n >> m;
   int x,k,y;
   vector<int> cnt(n+1);
   cin >> x >> k >> y;
   vector<int> a(n+2),b(m+2);
   vector<int> pos(n+2);
   f(i,1,n+1){
      cin >> a[i];
      pos[a[i]] = i;
   }
   f(i,1,m+1){
      cin >> b[i];
      cnt[b[i]]++;
   }
   int cur = 0;
   f(i,1,m+1){
      if(pos[b[i]] > cur){
         cur = pos[b[i]];
      }else{
         return cout << -1,0;
      }
   }
   vector<int> has(n+2);
   f(i,1,n+1){
      if(cnt[a[i]]){
         has[i] = 1;
      }
   }
   int ans = 0;
   f(i,1,n+1){
      if(has[i]) continue;
      vector<int> R;
      int prv = i-1;
      while(i <= n and !has[i]){
         R.pb(a[i]);
         i++;
      }
      int nxt = i;
      int sz = R.size();
      if(k*y >= x){
         int mx = max(a[prv],a[nxt]);
         int mxx = *max_element(all(R));
         if(mxx > mx){
            if(sz < k) return cout << -1,0;
         }
         ans += (sz/k)*x+(sz%k)*y;
      }else{
         int mx = max(a[prv],a[nxt]);
         int mxx = *max_element(all(R));
         if(mxx > mx){
            if(sz < k){
               return cout << -1,0;
            }
            ans += x+(sz-k)*y;
         }else{
            ans += sz*y;            
         }
      }
   }
   cout << ans << '\n';
   return 0;
}