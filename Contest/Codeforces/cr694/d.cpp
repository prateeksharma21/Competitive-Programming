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
const int MOD = 1e9+7, N = 1e6 + 10;

int lps[N];

void test(){
   int n;
   cin >> n;
   vector<int> K;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      int x = a[i];
      map<int, int> cnt;
      while (lps[x]) {
         cnt[lps[x]]++;
         x /= lps[x];
      }
      int t = 1;
      for (auto i : cnt) {
         if (i.second & 1) {
            t *= i.first;
         }
      }
      K.push_back(t);
   }
   sort(all(K));
   int ans0 = 0;
   int ans1 = 0;
   int even = 0;
   for (int i = 0, j = 0; i < K.size(); i = j) {
      while (j < K.size() and K[i] == K[j]) ++j;
      ans0 = max(ans0, j - i);
      ans1 = max(ans1, j - i);
      if ((j - i) % 2 ==  0 or K[i] == 1) {
         even += j - i;
      }
      ans1 = max(ans1, even);
   }
   int q;
   cin >> q;
   while (q--) {
      int w;
      cin >> w;
      if (w == 0) {
         cout << ans0 << '\n';
      } else {
         cout << ans1 << '\n';
      }
   }
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   for (int i = 2; i < N; ++i) {
      if (lps[i] == 0) {
         lps[i] = i;
         for (int j = i * i; j < N; j += i) {
            lps[j] = i;
         }
      }
   }
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}