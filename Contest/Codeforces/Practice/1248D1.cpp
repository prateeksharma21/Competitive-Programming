#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10; 

int pre[1010];
int t[4*1010];
int lazy[4*1010];
int sm[4*1010];

void push(int v){
   t[2*v] += lazy[v];
   lazy[2*v] += lazy[v];
   t[2*v+1] += lazy[v];
   lazy[2*v+1] += lazy[v];
   lazy[v] = 0;
}

void build(int v,int tl,int tr){
   if(tl == tr){
      t[v] = pre[tl];
   }else{
      int tm = (tl+tr)/2;
      build(2*v,tl,tm);
      build(2*v+1,tm+1,tr);
      t[v] = min(t[2*v],t[2*v+1]);
   }
}

void update(int v,int tl,int tr,int l,int r,int add){
   if(l > r) return;
   if(l == tl and tr == r){
      t[v] += add;
   }else{
      push(v);
      int tm = (tl+tr)/2;
      update(2*v,tl,tm,l,min(r,tm),add);
      update(2*v+1,tm+1,tr,max(l,tm+1),r,add);
      t[v] = min(t[2*v],t[2*v+1]);
   }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 1e9;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   string s;
   cin >> s;
   s += s;
   s = '#'+s;
   vector<int> A(2*n+1);
   f(i,1,2*n+1){
      A[i] = ((s[i]=='(')?1:-1);
      pre[i] = pre[i-1]+((s[i]=='(')?1:-1);
   }
   build(1,1,2*n);
   FenwickTree fen(A);
   vector<array<int,3>> Ans;
   f(i,1,n+1){
      f(j,i,n+1){
         if(s[i]!=s[j]){
            if(s[i] == '('){
               fen.update(i,-1);
               fen.update(i+n,-1);
               fen.update(j,1);
               fen.update(j+n,1);
               update(1,1,2*n,i,2*n,-2);
               update(1,1,2*n,i+n,2*n,-2);
               update(1,1,2*n,j,2*n,2);
               update(1,1,2*n,j+n,2*n,2);
            }else{
               fen.update(i,1);
               fen.update(i+n,1);
               fen.update(j,-1);
               fen.update(j+n,-1);
               update(1,1,2*n,i,2*n,2);
               update(1,1,2*n,i+n,2*n,2);
               update(1,1,2*n,j,2*n,-2);
               update(1,1,2*n,j+n,2*n,-2);
            }
         }
         cout << fen.sum(1,2*n) << '\n';
         swap(s[i],s[j]);
         swap(s[i+n],s[j+n]);
         int ans = 0;
         int lst = 2*n;
         while(lst>n){
            int v = fen.sum(lst-n);
            update(1,1,2*n,lst-n+1,lst,-v);
            if(fen.sum(lst-n+1,lst) == 0 and query(1,1,2*n,lst-n+1,lst) == 0){
               ans++;
            }
            update(1,1,2*n,lst-n+1,lst,v);
            cout << "st " << lst-n+1 << ' ' << lst << ' ' << ans << ' ' <<fen.sum(lst-n+1,lst) << '\n';
            lst--;
         }
         cout << s << '\n';
         cout << i << ' ' << j << ' ' << ans << '\n';
         Ans.pb({-ans,i,j});
         swap(s[i+n],s[j+n]);
         swap(s[i],s[j]);
         if(s[i]!=s[j]){
            if(s[i] == ')'){
               fen.update(i,-1);
               fen.update(i+n,-1);
               fen.update(j,1);
               fen.update(j+n,1);
               update(1,1,2*n,i,2*n,-2);
               update(1,1,2*n,i+n,2*n,-2);
               update(1,1,2*n,j,2*n,2);
               update(1,1,2*n,j+n,2*n,2);
            }else{
               fen.update(i,1);
               fen.update(i+n,1);
               fen.update(j,-1);
               fen.update(j+n,-1);
               update(1,1,2*n,i,2*n,2);
               update(1,1,2*n,i+n,2*n,2);
               update(1,1,2*n,j,2*n,-2);
               update(1,1,2*n,j+n,2*n,-2);
            }
         }
      }
   }
   sort(all(Ans));
   cout << -Ans[0][0] << ' ' << Ans[0][1] << ' ' << Ans[0][2] << '\n';
   return 0;
} 