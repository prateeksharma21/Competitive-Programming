#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
#define tree t
#define node v
#define start tl
#define end tr
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 2e5 + 10; 

int A[N];
int t[4*N];
int lazy[4*N];

void build(int v,int tl,int tr){
   if(tl == tr){
      t[v] = A[tl];
      return;
   }
   int tm = (tl+tr)/2;
   build(2*v,tl,tm);
   build(2*v+1,tm+1,tr);
   t[v] = t[2*v]+t[2*v+1];
}

void push(int v,int tl,int tr){
   if(lazy[v]){
      t[v] += (tr-tl+1)*lazy[v];
      if(tl!=tr){
         lazy[2*v] += lazy[v];
         lazy[2*v+1] += lazy[v];
      }
      lazy[v] = 0;
   }
}

void update(int v,int tl,int tr,int l,int r,int val){
   push(v,tl,tr);
   if(tl>r or tr<l) return;
   if(tl>=l and tr<=r){
      lazy[v] += val;
      push(v,tl,tr);
      return;
   }
   int tm = (tl+tr)/2;
   update(2*v,tl,tm,l,r,val);
   update(2*v+1,tm+1,tr,l,r,val);
   t[v] = t[2*v]+t[2*v+1];
}

int query(int v,int tl,int tr,int l,int r){
   if(tr<l or tl>r) return 0;
   push(v,tl,tr);
   if(tl>=l and tr<=r){
      return t[v];
   }
   int tm = (tl+tr)/2;
   return query(2*v,tl,tm,l,r)+query(2*v+1,tm+1,tr,l,r);
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q;
   cin >> n >> q;
   f(i,0,n){
      cin >> A[i];
   }
   build(1,0,n-1);
   while(q--){
      int ty;
      cin >> ty;
      if(ty == 1){
         int a,b,v;
         cin >> a >> b >> v;
         update(1,0,n-1,a-1,b-1,v);
      }else{
         int k;
         cin >> k;
         cout << query(1,0,n-1,k-1,k-1) << '\n';
      }
   }
   return 0;
} 