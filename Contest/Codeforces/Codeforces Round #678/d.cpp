#ifdef Prateek
  #include "\Prateek.h"
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
const int MOD = 1e9+7, N = 2e5 + 10; 

int n;
int p[N];
int a[N];
int parent[N];
vector<int> G[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n;
   for(int i = 2; i <= n; ++i) {
      cin >> p[i];
      G[p[i]].push_back(i);
      parent[i] = p[i];
   }

   for(int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   vector<int> leaf;
   for(int i = 1; i <= n; ++i) {
      if(G[i].empty()) {
         leaf.push_back(i);
      }
   }

   int l = 0, h = 1e16;
   int ans = -1;

   auto check = [&](int val) {
      vector<int> lf = leaf;
      vector<int> par(parent, parent+n+1);
      vector<int> A(a, a+n+1);

      function<int(int)> find = [&](int u) {
         if(par[u] == 0) return par[u];
         if(A[par[u]]) return par[u];
         return par[u] = find(par[u]);
      };

      while(!lf.empty()) {
         auto k = lf.back();
         lf.pop_back();
         vector<int> travel;
         int cur = par[k];
         if(A[k] > val) return false;
         while(cur) {
            A[k] += A[cur];
            A[cur] = 0;
            if(A[k] > val) {
               int extra = A[k]-val;
               A[cur] = extra;
               break;
            }
            cur = find(cur);
         }
      }

      for(int i = 1; i <= n; ++i) {
         if(!G[i].empty() and A[i]) {
            return false;
         }
      }
      return true;
   };

   int cnt = 0;
   while(l <= h) {
      int mid = (l+h) / 2;
      if(check(mid)) {
         ans = mid;
         h = mid-1;
      } else {
         l = mid+1;
      }
      ++cnt;
   }
   debug(cnt);

   cout << ans << '\n';
   return 0;
} 