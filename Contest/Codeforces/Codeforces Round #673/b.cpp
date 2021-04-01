#ifdef Prateek
  #include "C:\Prateek.h"
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
   int n, T;
   cin >> n >> T;
   vector<int> A(n);
   for(int &i : A) {
      cin >> i;
   }
   if(T & 1) {
      int mid = (T/2);
      for(int i = 0; i < n; ++i) {
         cout << (A[i] <= mid) << ' ';
      }
      cout << '\n';
   } else {
      int mid = T/2;
      int l = 0, r = 0;
      for(int i = 0; i < n; ++i) {
         if(A[i] == mid) {
            if(l <= r) {
               cout << 1 << ' ';
               ++l;
            } else {
               cout << 0 << ' ';
               ++r;
            }
         } else {
            cout << (A[i] < mid) << ' ';
         }
      }
      cout << '\n';
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
