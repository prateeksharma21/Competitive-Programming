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

void test(){
   int n;
   cin >> n;
   string s, p;
   cin >> s >> p;
   vector<int> z, o;
   for (int i = 0; i < n; ++i) {
      if (s[i] != p[i]) {
         if (s[i] == '0') {
            z.push_back(i);
         } else {
            o.push_back(i);
         }
      }
   }
   if (z.size() != o.size()) {
      cout << "No\n";
      return;
   }
   reverse(all(z));
   reverse(all(o));
   while (!z.empty()) {
      auto a = z.back();
      auto b = o.back();
      if (b > a) {
         cout << "No\n";
         return;
      }
      z.pop_back();
      o.pop_back();
   }
   cout << "Yes\n";
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