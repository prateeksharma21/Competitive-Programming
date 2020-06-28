#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds; 
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
template < typename T > using indexed_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
const int MOD = 1e9+7, N = 3e5 + 10; 

struct FenwickTree{
   int n;
   vector<ll> fenw;

   FenwickTree(int n){
      this->n = n;
      fenw.assign(n,0);
   }

   FenwickTree(vector<ll> a) : FenwickTree((int)a.size()){
      f(i,0,(int)a.size()){
         update(i,a[i]);
      }
   }

   ll sum(int r){
      ll res = 0;
      while(r>=0){
         res += fenw[r];
         r = r&(r+1);
         r--;
      }
      return res;
   }

   ll sum(int l,int r){
      return sum(r)-sum(l-1);
   }

   void update(int ind,ll val){
      while(ind<n){
         fenw[ind] += val;
         ind = ind | (ind+1);
      }
   }
};

FenwickTree val(N),cnt(N);

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m,k;
   cin >> n >> m >> k;
   vector<array<int,3>> A(n);
   vector<pair<int,int>> a,b,c,d;
   f(i,0,n){
      cin >> A[i][0] >> A[i][1] >> A[i][2];
      if(A[i][1] and A[i][2]){
         c.push_back({A[i][0],i});
      }else if(A[i][1]){
         a.push_back({A[i][0],i});
      }else if(A[i][2]){
         b.push_back({A[i][0],i});
      }else{
         d.push_back({A[i][0],i});
      }
   }
   sort(all(a));
   sort(all(b));
   sort(all(c));

   vector<pair<int, int>> n_a = a,n_b = b,n_c = c;

   int sza = a.size(), szb = b.size(), szc = c.size();
   if(sza+szc<k or szb+szc<k){
      cout << "-1\n";
      return 0;
   }
   indexed_set<pair<int, int>> s;
   int timer = 0;
   for(auto &e : n_a) s.insert(e);
   for(auto &e : n_b) s.insert(e);
   for(auto &e : d) s.insert(e);

   f(i,1,szc){
      c[i].F += c[i-1].F;
   }
   f(i,1,sza){
      a[i].F += a[i-1].F;
   }
   f(i,1,szb){
      b[i].F += b[i-1].F;
   }
   debug(a,b,c);
   int ans = 1e18;
   if(szc >= max(m,k)){
      ans = min(ans,c[max(m,k)-1].F);
   }

   int ca = 0, cb = 0,cc = szc-1;

   int sz = s.size();
   f(i,0,sza){
      int req = k-1-i;
      s.erase(n_a[i]);      
      int v = a[i].F;
      int rb = k;
      int books = i+1;
      int donea = i+1;
      int doneb = 0;
      if(req>0 and req <= szc){
         rb -= req;
         donea += req;
         doneb += req;
         books += req;
         while(cc != req-1){
            s.insert(n_c[cc]);
            cc--;
         }
         v += c[req-1].F;
      }
      if(rb>0 and rb <= szb){
         doneb += rb;
         books += rb;
         v += b[rb-1].F;
         while(cb <= rb-1){
            s.erase(n_b[cb]);
            cb++;
         }
      }
      if(doneb == k and donea == k and books <= m){
         int req = m-books;
         if(req){
            for(auto &e : s){
               req--;
               v += (e.F);
               if(!req) break;
            }
         }
         ans = min(ans,v);
      }
   }
   cout << ans << '\n';
   return 0;
}