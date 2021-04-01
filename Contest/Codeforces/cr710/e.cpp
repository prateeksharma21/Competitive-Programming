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


void Minimal(vector<int> A) {
   int n = A.size();
   set<int> rem;
   for (int i = 0; i < n; ++i) {
      rem.insert(i);
   }
   for (int i = 0; i < n; ++i) {
      if (rem.count(A[i])) {
         cout << A[i] + 1 << ' ';
         rem.erase(A[i]);
      } else {
         cout << *rem.begin() + 1 << ' ';
         rem.erase(rem.begin());
      }
   }
   cout << '\n';
} 

void Maximal(vector<int> A) {
   int n = A.size();
   set<int> rem;
   for (int i = 0; i < n; ++i) {
      rem.insert(i);
   }
   for (int i = 0; i < n; ++i) {
      auto k = rem.upper_bound(A[i]);
      --k;
      cout << *k  + 1 << ' ';
      rem.erase(k);
   }
   cout << '\n';
}

void test(){
   int n;
   cin >> n;
   vector<int> a(n);
   for (int &i : a) {
      cin >> i;
      --i;
   }
   Minimal(a);
   Maximal(a);
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