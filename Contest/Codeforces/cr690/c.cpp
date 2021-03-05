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

vector<string> ans[200];

void test(){
   int n;
   cin >> n;
   debug(n);
   if (ans[n].empty()) {
      cout << "-1\n";
   } else {
      cout << ans[n].front() << '\n';
   }
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   int n = 9;
   for (int i = 0; i < (1 << n); ++i) {
      string s;
      int sm = 0;
      for (int j = 0; j < n; ++j) {
         if ((i >> j) & 1) {
            s += (j + 1) + '0';
            sm += j + 1;
         }
      }
      // debug(sm);
      ans[sm].push_back(s);
   }
   for (int i = 1; i <= 50; ++i) {
      sort(all(ans[i]), [&](string a, string b){
         if (a.size() == b.size()) {
            return a < b;
         }
         return a.size() < b.size();
      });
   }
   debug(tt);
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}