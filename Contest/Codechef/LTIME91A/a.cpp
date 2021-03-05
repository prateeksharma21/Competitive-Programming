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
   string s;
   cin >> s;
   vector <int> freq(26);
   int n = s.length();
   for (int i = 0; i < n; ++i) {
      freq[s[i] - 'a']++;
   }
   int res = 0;
   int mn = n / 3;
   for (int i = 0; i < 26; ++i) {
      res += freq[i] / 2;
   }
   cout << min(res, mn) << '\n';
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