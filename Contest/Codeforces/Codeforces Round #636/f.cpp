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
 
void test(){
   int n;
   cin >> n;
   vector<set<int>> G(n-1);
   f(i,0,n-1){
      int k; cin >> k;
      f(j,0,k){
         int x; cin >> x;
         G[i].insert(x);
      }
   }
   for(int fst=1;fst<=n;fst++){
      vector<int> ans = {fst};
      int chk = 1;
      vector<set<int>> C = G;
      for(auto &i : C){
         if(i.find(fst)!=i.end()){
            i.erase(fst);
         }
      }
      while(ans.size()!=n){
         int cnt = 0;
         int el;
         for(auto &i : C){
            if(i.size() == 1){
               cnt++;
               el = *i.begin();
            }
         }
         if(cnt!=1) break;
         for(auto &i : C){
            if(i.find(el)!=i.end()){
               i.erase(el);
            }
         }
         ans.pb(el);
      }
      if(ans.size()!=n) continue;
      set<set<int>>  A(G.begin(),G.end());
      f(i,1,n){
         set<int> s;
         s.insert(ans[i]);
         int ff = 0;
         for(int j=i-1;j>=0;--j){
            s.insert(ans[j]);
            if(A.count(s)){
               ff = 1;
               A.erase(s);
               break;
            }
         }
         if(!ff) chk = 0;
      }
      if(chk){
         f(i,0,n){
            cout << ans[i] << " \n"[i==n-1];
         }
         return;
      }
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