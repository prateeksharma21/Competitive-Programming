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

struct SegTree{
   vector<int> t,lazy;
   vector<int> A;
   int n;

   SegTree(vector<int> a){
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

void test(){
   int n;
   cin >> n;
   vector<int> a(n);
   int ans = 0;
   f(i,0,n){
      cin >> a[i];
      if(i%2 == 0) ans += a[i];
   }

   if(n == 1){
      cout << ans << '\n';
      return;
   }

   int m = n/2;
   vector<int> pre(m);
   pre[0] = a[1]-a[0];
   int cur = 2;
   f(i,1,m){
      pre[i] = pre[i-1]+a[cur+1]-a[cur];
      cur += 2;
   }
   SegTree st(pre);
   int r = 0;
   cur = 0;
   f(i,0,m){
      r = max(r,st.query(i,m-1));
      st.update(i,m-1,a[cur]-a[cur+1]);
      cur += 2;
   }
   if(n <= 2){
      cout << ans+r << '\n';
      return;
   }
   int m1 = (n-1)/2;
   vector<int> pre1(m1);
   cur = 3;
   pre1[0] = a[1]-a[2];
   f(i,1,m1){
      pre1[i] = pre1[i-1]+a[cur]-a[cur+1];
      cur += 2;
   }
   SegTree tree(pre1);
   cur = 1;
   f(i,0,m1){
      r = max(r,tree.query(i,m1-1));
      tree.update(i,m1-1,a[cur+1]-a[cur]);
      cur += 2;
   }
   cout << ans+r << '\n';
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
