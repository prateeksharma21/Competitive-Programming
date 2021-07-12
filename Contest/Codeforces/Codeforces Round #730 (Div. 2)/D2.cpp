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

int n, k;

vector<int> getBase(int x) {
   vector<int> val;
   while (x) {
      val.push_back(x % k);
      x /= k;
   }
   while(val.size() < 25) val.push_back(0);
   reverse(all(val));
   return val;
}

int getOrig(vector<int> val) {
   int cur = 1;
   int ans = 0;
   for (int i = 24; i >= 0; --i) {
      ans += val[i] * cur;
      cur *= k;
   }
   return ans;
}

vector<int> getXor(vector<int> a, vector<int> b) {
   vector<int> res = a;
   for (int i = 0; i < 25; ++i) {
      res[i] += b[i];
      res[i] %= k;
   }
   return res;
}

void test(){
   cin >> n >> k;
   
   vector<int> cur(25);
   cout << 0 << endl;
   int r;
   cin >> r;
   if (r == 1) return;

   auto compute = [&](vector<int> a, vector<int> b) {
      vector<int> req(25);
      debug(k);
      for (int i = 0; i < 25; ++i) {
         req[i] = b[i] - a[i];
         debug(req[i], b[i], a[i]);
         if (req[i] < 0) req[i] += k;
      }
      return req;
   };


   auto cor = [&](vector<int> a, vector<int> b) {
      vector<int> req(25);
      for (int i = 0; i < 25; ++i) {
         req[i] = b[i] + a[i];
         req[i] %= MOD;
      }
      return req;
   };


   for (int i = 1; i < n; ++i) {
      vector<int> target = get(i);
      debug(target, cur);
      vector<int> req = compute(cur, target);
      debug(req);
      int k = revget(req);
      cout << k << endl;
      assert(cor(get(k), cur) == target);
      cin >> k;
      if (k == 1) return;
      cur = target;
   }

   assert(false);

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