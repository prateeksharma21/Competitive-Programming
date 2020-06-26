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
   int n;
   cin >> n;
   vector<int> a(n),b(n);
   int sma = 0, smb = 0;
   f(i,0,n){
      cin >> a[i];
      sma += a[i];
   }
   f(i,0,n){
      cin >> b[i];
      smb += b[i];
   }
   if(sma > smb){
      cout << "NO\n";
      return;
   }
   int st = 0;
   while(a[st] > b[st]){
      st++;
   }
   if(!st){
      while(a[st] <= b[st]){
         st--;
         st += n;
         st %= n;
         if(st == 0) break;
      }
      if(st == 0){
         cout << "YES\n";
         return;
      }
      st++;
      st %= n;
   }
   vector<pair<int, int>> P;
   vector<int> vis(n);
   while(1){
      int bg = st;
      while(a[st] <= b[st]){
         vis[st] = 1;
         st++;
         st %= n;
      }
      st--;
      st += n;
      st %= n;
      P.pb({bg,st});
      st++;
      st %= n;
      bg = st;
      while(a[st] > b[st]){
         vis[st] = 1;
         st++;
         st %= n;
      }
      st--;
      st += n;
      st %= n;
      P.pb({bg,st});
      st++;
      st %= n;
      if(vis[st]) break;
   }
   f(i,0,n){
      if(b[i] < a[i]){
         int j = i;
         debug(j);
         vector<int> vis(n);
         vector<int> ta = a,tb = b;
         while(vis[j] != 2){
            vis[j] += 1;
            int rem = ta[j]-tb[j];
            debug(rem);
            if(rem <= 0) break;
            int cur =  j;
            j--;
            j += n;
            j %= n;
            int have = tb[j];
            if(have < rem) break;
            have -= rem;
            tb[cur] = ta[cur];
            tb[j] = have;
         }
         int chk = 1;
         debug(ta,tb);
         f(j,0,n){
            if(ta[j]>tb[j]){
               chk = 0;
            }
         }
         if(chk){
            cout << "YES\n";
            return;
         }
      }
   }
   cout << "NO\n";
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
