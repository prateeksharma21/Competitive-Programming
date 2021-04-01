#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define f(i,x,n) for(ll i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define ll int

template < typename T > using indexed_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;

using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
 
const double PI = acos(-1);
const ll LINF = LLONG_MAX;
const int MOD = 1e9+7, INF = INT_MAX, N = 1e5 + 10;

#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif

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

   void range_add(int l, int r, int val) {
       update(l, val);
       update(r + 1, -val);
   }

};

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q;
   cin >> n >> q;
   int x;
   vector<int> cnt(n+1);
   f(i,0,n){
      cin >> x;
      cnt[x]++;
   }
   FenwickTree fen(n+2);
   int cur = 0;
   f(i,1,n+1){
      cur += cnt[i];
      fen.range_add(i,i,cur);
   }
   int c = n;
   while(q--){
      cin >> x;
      if(x>0){
         cnt[x]++;
         fen.range_add(x,n,1);
      }else{
         x = abs(x);
         int l = 1,h = n,ans = n;
         // f(i,1,n+1){
         //    cout << fen.sum(i) << ' ';
         // }
         // cout << '\n';
         while(l<=h){
            int mid = l+h>>1;
            if(fen.sum(mid)>=x){
               ans = mid;
               h = mid-1;
            }else{
               l = mid+1;
            }
         }
         cnt[ans]--;
         // cout << ans << '\n';
         fen.range_add(ans,n,-1);
         // fen.
      }
   }
   f(i,1,n+1){
      if(cnt[i]){
         cout << i << '\n';
         return 0;
      }
   }
   cout << "0\n";
   return 0;
}
