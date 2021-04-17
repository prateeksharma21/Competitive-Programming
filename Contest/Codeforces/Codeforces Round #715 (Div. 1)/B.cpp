#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

int cur;
vector<int> r;
int n, k;


void solve(int x) {
   if (x == 0) return;
   if (x == 1) {
      r.push_back(cur);
      ++cur;
      return;
   }
   if (x > 62) {
      r.push_back(cur);
      ++cur;
      solve(x - 1);
   } else {
      vector<int> a;
      int v = (1LL << (x - 1));
      debug(v, r, k);
      assert(k <= v);
      int tot = v / 2;
      v = (v + 1) / 2;
      while (true) {
         a.push_back(cur);
         ++cur;
         if (k <= tot) {
            break;
         } else {
            tot += (v + 1) / 2;
            v = (v + 1) / 2;
         }
      }
      debug(a, tot);
      int sz = a.size();
      v = (1LL << (x - 1)) / 2;
      while (sz > 1) {
         k -= v;
         --sz;
         v /= 2;
      }
      reverse(all(a));
      for (int i : a) r.push_back(i);
      solve(x - (int)a.size());
   }
}

void test(){
   cin >> n >> k;
   cur = 1;
   r.clear();
   if (n <= 63) {
      int mx = (1LL << (n - 1));
      if (k > mx) {
         cout << -1 << '\n';
         return;
      }
   }
   debug('1');
   solve(n);
   for (int i : r) {
      cout << i << ' ';
   }
   cout << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}