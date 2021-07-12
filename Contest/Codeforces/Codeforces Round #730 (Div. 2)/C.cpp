#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
// #define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   long double c, m, p, v;
   cin >> c >> m >> p >> v;
   string s = "";
   long double ans = 0;
   for (int len = 0; len <= 19; ++len) {
      long double res = 0;
      for (int i = 0; i < (1 << len); ++i) {
         auto C = c, M = m, P = p, V = v;
         C *= 10000, M *= 10000, P *= 10000, V *= 10000;

         long double p = 1;
         for (int j = 0; j < len; ++j) {
            if (i >> j & 1) {
               p *= C / 10000;
               if (C <= V) {
                  if (M != 0) {
                     M += C / 2;
                     P += C / 2;
                  } else {
                     P += C;
                  }
                  C = 0;
               } else {
                  if (M != 0) {
                     M += V / 2;
                     P += V / 2;
                  } else {
                     P += V;
                  }
                  C -= V;
               }
            } else {
               p *= M / 10000;
               if (M <= V) {
                  if (C != 0) {
                     C += M / 2;
                     P += M / 2;
                  } else {
                     P += M;
                  }
                  M = 0;
               } else {
                  if (C != 0) {
                     C += V / 2;
                     P += V / 2;
                  } else {
                     P += V;
                  }
                  M -= V;
               }
            }
            if (p == 0) break;
         }
         p *= P / 10000;
         res += (len + 1) * p;         
      }
      ans += res;
   }  
   cout << setprecision(14) << fixed << ans << '\n';
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