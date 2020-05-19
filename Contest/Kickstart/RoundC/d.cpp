#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;
 
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


void test(){
   int n,q,p = 1;
   cin >> n >> q;
   vector<int> A(n+1),B(n+1);
   f(i,1,n+1){
      cin >> A[i];
      B[i] = p*i*A[i];
      A[i] = p*A[i];
      p = -p;
   }
   FenwickTree f0(A),f1(B);
   
   auto update = [&](int i,int v){
      if(!(i&1)) v = -v;
      f0.update(i,v-A[i]);
      f1.update(i,(v-A[i])*i);
      A[i] = v;
   };

   int R = 0;

   while(q--){
      char c;
      cin >> c;
      if(c == 'U'){
         int x,v;
         cin >> x >> v;
         update(x,v);
      }else{
         int l,r;
         cin >> l >> r;
         int ans = f1.sum(l,r)-(l-1)*f0.sum(l,r);
         if(!(l&1)) ans = -ans;
         R +=ans;
      }
   }

   cout << R << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,1,tt+1){
      cout << "Case #" << i << ": ";
      test();
   }
   return 0;
}