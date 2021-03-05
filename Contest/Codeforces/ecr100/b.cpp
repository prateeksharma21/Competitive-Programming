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
   int n;
   cin >> n;
   vector<int> a(n);
   int sm = 0;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sm += a[i];
   }
   {
      vector<int> b = a;
      int c = 0;
      for (int i = 0; i < n; i += 2) {
         b[i] = 1;
      }
      for (int i = 0; i < n; ++i) {
         c += abs(a[i] - b[i]);
      }
      if (2 * c <= sm) {
         for (int i : b) {
            cout << i << ' ';
         }
         cout << '\n';
         return;
      }
   }
   {
      vector<int> b = a;
      int c = 0;
      for (int i = 1; i < n; i += 2) {
         b[i] = 1;
      }
      for (int i = 0; i < n; ++i) {
         c += abs(a[i] - b[i]);
      }
      if (2 * c <= sm) {
         for (int i : b) {
            cout << i << ' ';
         }
         cout << '\n';
         return;
      }
   }
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