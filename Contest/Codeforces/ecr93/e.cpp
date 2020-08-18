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
#define int ll

template < typename T > using indexed_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;

using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
 
const double PI = acos(-1);
const ll LINF = LLONG_MAX;
const int MOD = 1e9+7, INF = INT_MAX, N = 1e5 + 10;

#ifdef Prateek
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif

template<typename T>
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
   int n;
   cin >> n;
   map<int,int> mp;
   vector<pair<int, int>> Q(n);
   for(int i = 0; i < n; ++i){
      int ty,d;
      cin >> ty >> d;
      Q[i] = {ty,d};
      if(d > 0){
         mp[d];
      }
   }
   int c = 0;
   for(auto &e : mp){
      e.second = c++;
   }
   indexed_set<int> t0,t1,t;
   FenwickTree<int> sm(c+10);
   for(int i = 0; i < n; ++i){
      int ty = Q[i].first, d = Q[i].second;
      if(ty == 0){
         if(d > 0){
            t0.insert(d);
            sm.update(mp[d],d);
         }else{
            t0.erase(-d);
            sm.update(mp[-d],d);
         }
      }else{
         if(d > 0){
            t1.insert(d);
            sm.update(mp[d],d);
         }else{
            t1.erase(-d);
            sm.update(mp[-d],d);
         }
      }

      if(d > 0){
         t.insert(d);
      }else{
         t.erase(-d);
      }

      // debug(t0,t1);

      if(t0.empty() and t1.empty()){
         cout << "0\n";
         continue;
      }

      if(t1.empty()){
         cout << sm.sum(0,c+9) << '\n';
         continue;
      }

      if(t0.empty()){
         cout << 2*sm.sum(0,c+9)-(*t1.begin()) << '\n';
         continue;
      }

      if(t1.size() == 1){
         cout << sm.sum(0,c+9)+(*t0.rbegin()) << '\n';
         continue;
      }

      if(*t1.begin() > *t0.rbegin()){
         auto st = t1.begin();
         st++;
         int idx = mp[*st];
         cout << sm.sum(0,idx-1)+2*sm.sum(idx,c+9)+*t0.rbegin() << '\n';
         continue;
      }
      int dbl = (int)t1.size();
      int rem = (int)t.size()-dbl;
      auto kk = *t.find_by_order(rem);
      int idx = mp[kk];
      cout << sm.sum(0,idx-1)+2*sm.sum(idx,c+9) << '\n';
   }
   return 0;
}

