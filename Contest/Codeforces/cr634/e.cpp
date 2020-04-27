#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;
 
int lim = 201;

void test(){
   int n;
   cin >> n;
   vector<int> a(n+1);
   vector<vector<int>> cnt(n+1,vector<int>(lim));
   vector<int> fst(lim,1e9),lst(lim);
   vector<int> pos[lim];
   f(i,1,n+1){
      cin >> a[i];
      cnt[i] = cnt[i-1];
      cnt[i][a[i]]++;
      pos[a[i]].pb(i);
      fst[a[i]] = min(fst[a[i]],i);
      lst[a[i]] = max(lst[a[i]],i);
   }
   int ans = 0;
   f(i,1,n+1){
      int va = a[i];
      ans = max(ans,cnt[n][va]);
      int c = cnt[i][va];
      if(c > cnt[n][va]/2) continue;
      int st = c,en = cnt[n][va]-c+1;
      int val = 0;
      f(j,1,lim){
         if(j==va) continue;
         val = max(val,cnt[pos[va][en-1]][j]-cnt[pos[va][st-1]][j]);
      }
      ans = max(ans,2*c+val);
   }
   cout << ans << '\n';
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
