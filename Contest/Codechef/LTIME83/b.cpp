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
const int MOD = 998244353, N = 5e5 + 10;
 
int A[N];
int sm[4*N],sq[4*N];
int lazy[4*N];

void build(int v,int tl,int tr){
   if(tl == tr){
      sm[v] = A[tl];
      sq[v] = (sm[v]*sm[v])%MOD;
      return;
   }
   int tm = (tl+tr)/2;
   build(2*v,tl,tm);
   build(2*v+1,tm+1,tr);
   sm[v] = (sm[2*v]+sm[2*v+1])%MOD;
   sq[v] = (sq[2*v]+sq[2*v+1])%MOD;
}

void push(int v,int tl,int tr){
   if(lazy[v]){
      int ff = (lazy[v]*lazy[v])% MOD;
      sq[v] += 2*lazy[v]*sm[v]+ff*(tr-tl+1);
      sq[v] %= MOD;
      sm[v] += (tr-tl+1)*lazy[v];
      sm[v] %= MOD;
      if(tl!=tr){
         lazy[2*v] += lazy[v];
         lazy[2*v] %= MOD;
         lazy[2*v+1] += lazy[v];
         lazy[2*v+1] %= MOD;
      }
      lazy[v] = 0;
   }
}

void update(int v,int tl,int tr,int l,int r,int val){
   push(v,tl,tr);
   if(tl>r or tr<l) return;
   if(tl>=l and tr<=r){
      lazy[v] += val;
      lazy[v] %= MOD;
      push(v,tl,tr);
      return;
   }
   int tm = (tl+tr)/2;
   update(2*v,tl,tm,l,r,val);
   update(2*v+1,tm+1,tr,l,r,val);
   sm[v] = (sm[2*v]+sm[2*v+1])%MOD;
   sq[v] = (sq[2*v]+sq[2*v+1])%MOD;
}

int query(int v,int tl,int tr,int l,int r){
   push(v,tl,tr);
   if(tr<l or tl>r) return 0;
   if(tl>=l and tr<=r){
      return sq[v];
   }
   int tm = (tl+tr)/2;
   return (query(2*v,tl,tm,l,r)+query(2*v+1,tm+1,tr,l,r))%MOD;
}

void test(){
   int n,m,q;
   cin >> n >> m >> q;
   f(i,0,4*m+5){
      A[i] = sm[i] = sq[i] = lazy[i] = 0;
   }
   vector<int> a(n+1);
   f(i,1,n+1){
      cin >> a[i];
   }
   vector<int> pre(n+1);
   f(i,1,n+1){
      pre[i] = pre[i-1]+a[i];
      pre[i] %= MOD;
   }
   int ans = 0;
   f(i,1,m+1){
      A[i] = (pre[n-m+i]-pre[i-1]+MOD) % MOD;
   }
   build(1,1,m);
   while(q--){
      int pos,val;
      cin >> pos >> val;
      int mn = max(1ll,pos-(n-m+1)+1);
      int mx = min(m,pos);
      int inc = (val-a[pos]+MOD)%MOD;
      update(1,1,m,mn,mx,inc);
      a[pos] = val;
      cout << query(1,1,m,1,m) << '\n';
   }
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
