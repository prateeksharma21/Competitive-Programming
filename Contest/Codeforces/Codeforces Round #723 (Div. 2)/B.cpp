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

vector<int> pw;

void test(){
   int n;
   cin >> n;
   int t = n / 11;
   int rem = n % 11;
   if (rem > t / 10) {
      cout << "NO\n";
   } else {
      cout << "YES\n";
   }
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   pw.push_back(1);
   for (int i = 0; i < 10; ++i) {
      pw.push_back(pw.back() * 10);
   }
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}