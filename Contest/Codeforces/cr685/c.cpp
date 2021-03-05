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
   int n, k;
   cin >> n >> k;
   string a, b;
   cin >> a >> b;
   vector<int> cnt1(26), cnt2(26);
   for (char i : a) {
      cnt1[i - 'a']++;
   }
   for (char i : b) {
      cnt2[i - 'a']++;
   }
   for (int i = 0; i < 26; ++i) {
      if (cnt1[i] < cnt2[i]) {
         // debug(i);
         cout << "NO\n";
         return;
      }
      int extra = cnt1[i] - cnt2[i];
      if (i + 1 < 26) {
         cnt1[i+1] += k * (extra/k);
      }
   }
   cout << "YES\n";
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
