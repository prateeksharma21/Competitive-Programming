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

vector<int> invert = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
int HH, MM;

bool same(int h, int m) {
   string H = to_string(h);
   if (H.length() == 1) H = "0" + H;
   for (char c : H) {
      if (invert[c - '0'] == -1) return false;
   }
   string M = to_string(m);
   if (M.length() == 1) M = "0" + M;
   for (char c : M) {
      if (invert[c - '0'] == -1) return false;
   }   
   int hr = invert[M[1] - '0'] * 10 + invert[M[0] - '0'];
   int mn = invert[H[1] - '0'] * 10 + invert[H[0] - '0'];
   if (hr < HH and mn < MM) {
      cout << H << ':' << M << '\n';
      return true;
   }
   return false;
}

void test(){
   cin >> HH >> MM;
   string T;
   cin >> T;
   int h = (T[0] - '0') * 10 + T[1] - '0';
   int m = (T[3] - '0') * 10 + T[4] - '0';
   while (!same(h, m)) {
      ++m;
      if (m == MM) {
         m = 0;
         ++h;
      }
      if (h == HH) {
         h = 0;
      }
   }
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