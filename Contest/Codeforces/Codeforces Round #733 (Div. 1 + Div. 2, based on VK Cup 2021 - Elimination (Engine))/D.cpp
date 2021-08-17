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

void test(){
   int n;
   cin >> n;
   vector<int> a(n), b;
   vector<int> nxt(n);
   int cnt = 0;
   map<int, int> done;
   vector<int> in, ou;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      nxt[i] = a[i];
      if (done[a[i]]) { 
         ou.push_back(i);
         ++cnt;
      }
      done[a[i]]++;
   }
   cout << n - cnt << '\n';
   b = a;
   for (int i = 0; i < n; ++i) {
      if (!done[i]) in.push_back(i);
   }
   if (cnt == 0) {
      for (int i : a) {
         cout << i + 1 << ' ';
      }
      cout << '\n';
      return;
   }
   if (in.size() == 1) {
      if (in.front() == ou.front()) {
         int nx = nxt[in.front()], nd = -1;
         for (int i = 0; i < n; ++i) {
            if (i != in.front() and nxt[i] == nx) {
               nd = i;
               break;
            }
         }
         assert(nd != -1);
         assert(nd != in.front());
         a[nd] = in.front();
         a[in.front()] = nx;
         int ans = 0;
         map<int, int> dn;
         for (int i = 0; i < n; ++i) {
            assert(a[i] != i);
            ans += (a[i] == b[i]);
            assert(!dn[a[i]]);
            dn[a[i]] = 1;
         }
      } else {
         a[ou.front()] = in.front();
         int ans = 0;
         map<int, int> dn;
         for (int i = 0; i < n; ++i) {
            assert(a[i] != i);
            ans += (a[i] == b[i]);
            assert(!dn[a[i]]);
            dn[a[i]] = 1;
         }
      }
      // cout << n - 1 << '\n';
      int K = n - cnt;
      int ans = 0;
      map<int, int> dn;
      for (int i = 0; i < n; ++i) {
         // assert(a[i] != i);
         ans += (a[i] == b[i]);
         assert(!dn[a[i]]);
         dn[a[i]] = 1;
      }
      assert(ans == K);
      for (int i : a) cout << i + 1 << ' ';
      cout << '\n';
      return;
   }

   while (in.size() > 2) {
      int x = ou.back();
      int y = in.back();
      ou.pop_back();
      in.pop_back();
      if (x == y) {
         int t = in.back();
         in.pop_back();
         in.push_back(y);
         y = t;
      }
      assert(x != y);
      a[x] = y;
   }
   sort(all(in));
   sort(all(ou));
   do {
      int c = 1;
      for (int i = 0; i < 2; ++i) c &= (in[i] != ou[i]);
      if (c) {
         for (int i = 0; i < 2; ++i) {
            a[ou[i]] = in[i];
         }
      } 
   } while (next_permutation(all(in)));
   int K = n - cnt;
   int ans = 0;
   map<int, int> dn;
   for (int i = 0; i < n; ++i) {
      ans += (a[i] == b[i]);
      // assert(a[i] != i);
      assert(!dn[a[i]]);
      dn[a[i]] = 1;
   }
   assert(ans == K);
   for (int i : a) {
      cout << i + 1 << ' ';
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