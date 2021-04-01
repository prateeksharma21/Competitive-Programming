#ifdef Prateek
  #include "\Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

template <typename T>
struct FenwickTree{
   int n;
   vector<T> fenw;
   FenwickTree(int n){
      this->n = n;
      fenw.assign(n,0);
   }
   FenwickTree(vector<T> a) : FenwickTree((int)a.size()){
      for(int i = 0; i < a.size(); ++i){
         update(i,a[i]);
      }
   }
   T sum(int r){
      long long res = 0;
      while(r>=0){
         res += fenw[r];
         r = r&(r+1);
         r--;
      }
      return res;
   }
   T sum(int l,int r){
      return sum(r)-sum(l-1);
   }
   void update(int ind,T val){
      while(ind < n){
         fenw[ind] += val;
         ind = ind | (ind+1);
      }
   }
   void range_upd(int l, int r, T val){
      update(l,val);
      update(r+1,-val);
   }
};

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   string s;
   cin >> s;
   string tar = s;
   reverse(all(tar));
   int l = 0, h = n-1;
   set<int> pos[26];
   FenwickTree<int> tree(n);
   for(int i = 0; i < n; ++i) {
      pos[s[i]-'a'].insert(i);
   }
   set<int> se;
   for(int i = 0; i < n; ++i) {
      se.insert(i);
   }
   int ans = 0;
   int cl = 0, cr = n-1;
   while(se.size() > 1) {
      auto l = *se.begin();
      auto r = *se.rbegin();
      if(s[l] == s[r] and s[cl] == s[l]) {
         se.erase(l);
         pos[s[l]-'a'].erase(l);
         se.erase(r);
         pos[s[r]-'a'].erase(r);
         tree.update(l,1);
         tree.update(r,1);
      } else {
         // debug(l, r);

         auto k1 = pos[s[cr]-'a'].lower_bound(l);
         auto k2 = pos[s[cl]-'a'].upper_bound(r);
         --k2;

         auto ff = *k1;
         auto ss = *k2;

         // debug(ff, ss);
         // debug(s[ff], s[ss]);
         ans += ff-l-tree.sum(l,ff);
         ans += r-ss-tree.sum(ss,r);
         if(ff > ss)
            --ans;
         // debug(ans);
         tree.update(ff,1);
         tree.update(ss,1);
         se.erase(ff);
         pos[s[cl]-'a'].erase(ss);
         se.erase(ss);
         pos[s[cr]-'a'].erase(ff);
      }
      ++cl, --cr;
   }

   cout << ans << '\n';
   return 0;
}