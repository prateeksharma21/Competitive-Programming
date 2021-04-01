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
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n, q;
   cin >> n >> q;
   string s;
   cin >> s;
   while (q --) {
      int l, r;
      cin >> l >> r;
      l--,r--;
      string req = s.substr(l, r - l + 1);
      debug(req);
      vector <int> pos;
      int j = 0, i = 0;
      int sz = r - l + 1;
      for (i = 0; i < n and j < sz; ++i) {
         if (s[i] == req[j]) {
            ++j;
            pos.push_back(i);
         }
      }
      if (j != sz) {
         cout << "NO\n";
         continue;
      }
      if (sz == 1) {
         cout << "YES\n";
         continue;
      }

      int chk = 1;
      for (int i = 1; i < pos.size(); ++i) {
         chk &= (pos[i-1] + 1 == pos[i]);
      }
      if(!chk) {
         cout << "YES\n";
         continue;
      }
      int fn = 0;
      while (i < n) {
         if (req.back() == s[i]) {
            fn = 1;
         }
         ++i;
      } 
      if (fn) {
         cout << "YES\n";
      } else {
         cout << "NO\n";
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
