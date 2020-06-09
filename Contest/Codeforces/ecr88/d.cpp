#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

int nxt[N];
int prv[N];

#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif

struct SegTreeMax{
   vector<int> t,lazy;
   vector<int> A;
   int n;

   SegTreeMax(vector<int> a){
      this->n = a.size();
      this->A = a;
      this->t.assign(4*n,0);
      this->lazy.assign(4*n,0);
      build(1,0,n-1);
   }

   int fun(int a,int b){
      return max(a,b);
   }

   void build(int v,int tl,int tr){
      if(tl == tr){
         t[v] = A[tl];
      }else{
         int tm = (tl+tr)/2;
         build(2*v,tl,tm);
         build(2*v+1,tm+1,tr);
         t[v] = fun(t[2*v],t[2*v+1]);
      }
   }

   void push(int v) {
      t[v*2] += lazy[v];
      lazy[v*2] += lazy[v];
      t[v*2+1] += lazy[v];
      lazy[v*2+1] += lazy[v];
      lazy[v] = 0;
   }

   void update(int v, int tl, int tr, int l, int r, int addend) {
      if (l > r) 
         return;
      if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
      } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = fun(t[v*2], t[v*2+1]);
      }
   }

   int query(int v, int tl, int tr, int l, int r) {
      if (l > r)
        return LLONG_MIN;
      if (l <= tl && tr <= r)
        return t[v];
      push(v);
      int tm = (tl + tr) / 2;
      return fun(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
   }

   void update(int l,int r,int val){
      update(1,0,n-1,l,r,val);
   }

   void update(int i,int val){
      update(i,i,val);
   }

   int query(int l,int r){
      return query(1,0,n-1,l,r);
   }

   int query(int i){
      return query(i,i);
   }
};

struct SegTreeMin{
   vector<int> t,lazy;
   vector<int> A;
   int n;

   SegTreeMin(vector<int> a){
      this->n = a.size();
      this->A = a;
      this->t.assign(4*n,0);
      this->lazy.assign(4*n,0);
      build(1,0,n-1);
   }

   int fun(int a,int b){
      return min(a,b);
   }

   void build(int v,int tl,int tr){
      if(tl == tr){
         t[v] = A[tl];
      }else{
         int tm = (tl+tr)/2;
         build(2*v,tl,tm);
         build(2*v+1,tm+1,tr);
         t[v] = fun(t[2*v],t[2*v+1]);
      }
   }

   void push(int v) {
      t[v*2] += lazy[v];
      lazy[v*2] += lazy[v];
      t[v*2+1] += lazy[v];
      lazy[v*2+1] += lazy[v];
      lazy[v] = 0;
   }

   void update(int v, int tl, int tr, int l, int r, int addend) {
      if (l > r) 
         return;
      if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
      } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = fun(t[v*2], t[v*2+1]);
      }
   }

   int query(int v, int tl, int tr, int l, int r) {
      if (l > r)
        return LLONG_MAX;
      if (l <= tl && tr <= r)
        return t[v];
      push(v);
      int tm = (tl + tr) / 2;
      return fun(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
   }

   void update(int l,int r,int val){
      update(1,0,n-1,l,r,val);
   }

   void update(int i,int val){
      update(i,i,val);
   }

   int query(int l,int r){
      return query(1,0,n-1,l,r);
   }

   int query(int i){
      return query(i,i);
   }
};


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> A(n+1),pre(n+1);
   f(i,1,n+1){
      cin >> A[i];
      pre[i] = pre[i-1]+A[i];
   }
   map<int,int> occ;
   for(int i = n;i>=1;i--){
      int v = 1e18;
      // debug(A[i]);
      for(int j = A[i]+1;j<=30;j++){
         if(occ[j]){
            // cout << j << ' ' << occ[j]<< '\n';
            v = min(v,occ[j]);
         }
      }
      // debug(v);
      if(v == 1e18){
         nxt[i] = n;
      }else{
         nxt[i] = v-1;
      }
      occ[A[i]] = i;
   }
   occ.clear();
   for(int i = 1;i<=n;i++){
      int v = 0;
      for(int j = A[i]+1;j<=30;j++){
         if(occ[j]){
            v = max(v,occ[j]);
         }
      }
      if(v == 0){
         prv[i] = 0;
      }else{
         prv[i] = v+1;
      }
      occ[A[i]] = i;
      // debug(v);
   }
   // debug(pre);
   SegTreeMin tmin(pre);
   SegTreeMax tmax(pre);
   int ans = 0;
   f(i,1,n+1){
      itn mx = tmax.query(i,nxt[i]);
      // if(prv[i] == i){
      //    ans = max(ans,mx-pre[i-1]);
      //    continue;
      // }
      int mn = tmin.query(prv[i]-1,i-1);      
      // debug(mn,mx);
      // debug(prv[i],nxt[i]);
      int v = mx-mn;
      // debug(v);
      v -= A[i];
      ans = max(ans,v);
      // debug(ans,v);
      // ans = max(ans,pre[nxt[i]]-pre[prv[i]]-A[i]);
   }
   cout << ans << '\n';
   return 0;
}