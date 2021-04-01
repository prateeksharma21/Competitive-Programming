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
const int MOD = 1e9+7, N = 1e6 + 10; 

template<class T>
struct Fenwick{
   int n;
   vector<T> bit;

   Fenwick(int n){
      this->n = n;
      bit.assign(n,0);
   }

   Fenwick(vector<T> a) : Fenwick((int)a.size()){
      for(int i = 0; i < int(a.size()); ++i){
         update(i,a[i]);
      }
   }

   T query(int r){
      T res = 0;
      while(r>=0){
         res += bit[r];
         r = r&(r+1);
         r--;
      }
      return res;
   }

   T query(int l,int r){
      return query(r)-query(l-1);
   }

   void update(int i,T val){
      while(i < n){
         bit[i] += val;
         i = i | (i+1);
      }
   }

   void range_add(int l,int r,T val){
      update(l,val);
      update(r+1,-val);
   }
};

Fenwick<int> Tree(N);
vector<pair<int, int>> P[N];
int ans[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q;
   cin >> n >> q;
   vector<int> A(n+1);
   for(int i = 1; i <= n; ++i){
      cin >> A[i];
      A[i] = i-A[i];
   }
   debug(A);
   for(int i = 1; i <= q; ++i){
      int x,y;
      cin >> x >> y;
      int l = x+1, r = n-y;
      debug(l,r);
      P[r].push_back({l,i});
   }
   for(int i = 1; i <= n; ++i){
      debug(P[i]);
      if(A[i] >= 0){
         int l = 1, r = i;
         int ans = 0;
         while(l <= r){
            int m = (l+r)/2;
            int v = Tree.query(m);
            if(v >= A[i]){
               ans = m;
               l = m+1;
            }else{
               r = m-1;
            }
         }
         Tree.range_add(1,ans,1);
      }
      for(pair<int, int> v : P[i]){
         ans[v.second] = Tree.query(v.first);
      }
   }
   for(int i = 1; i <= q; ++i){
      cout << ans[i] << "\n";
   }
   return 0;
}