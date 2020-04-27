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
const int MOD = 1e9+7, INF = INT_MAX, N = 2e5 + 10;
 
int t[4*N],A[N];

void build(int v,int tl,int tr){
   if(tl == tr){
      t[v] = A[tl];
      return;
   }
   int tm = (tl+tr)/2;
   build(2*v,tl,tm);
   build(2*v+1,tm+1,tr);
   t[v] = min(t[2*v],t[2*v+1]);
}

int query(int v,int tl,int tr,int l,int r){
   if(l>r) return INF;
   if(tl == l and tr == r){
      return t[v];
   }
   int tm = (tl+tr)/2;
   return min(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr,max(tm+1,l),r));
}

void update(int v,int tl,int tr,int pos,int val){
   if(tl == tr){
      t[v] = val;
      return;
   }
   int tm = (tl+tr)/2;
   if(pos <= tm){
      update(2*v,tl,tm,pos,val);
   }else{
      update(2*v+1,tm+1,tr,pos,val);
   }
   t[v] = min(t[2*v],t[2*v+1]);
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q;
   cin >> n >> q;
   for (int i = 1; i < n+1; ++i)
   {
      cin >> A[i];
   }
   build(1,1,n);
   while(q--){
      int a,b,ty;
      cin >> ty >> a >> b;
      if(ty == 1){
         update(1,1,n,a,b);
      }else{
         cout << query(1,1,n,a,b) << '\n';
      }
   }
   return 0;
}
