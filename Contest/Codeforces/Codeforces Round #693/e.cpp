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
   vector<array<int, 3>> A(n);
   for (int i = 0, h, w; i < n; ++i) {
      cin >> h >> w;
      A[i] = {h, w, i};
   }
   vector<int> ans(n, -2);
   sort(all(A));
   vector<array<int, 2>> B(n);
   vector<int> mn(n), pos(n);
   int cur_mn = 1e9 + 1, cur_pos = -1;
   for (int i = 0; i < n; ++i) {
      if (cur_mn > A[i][1]) {
         cur_mn = A[i][1];
         cur_pos = A[i][2];
      }
      B[i] = {A[i][0], A[i][1]};
      mn[i] = cur_mn;
      pos[i] = cur_pos;
   }
   for (int i = 0; i < n; ++i) {
      auto [h, w, ix] = A[i];
      auto k = lower_bound(all(B), array<int, 2>({h, -1})) - B.begin();
      if (k != 0) {
         --k;
         if (mn[k] < w) {
            ans[ix] = pos[k];
         } 
      }

      swap(h, w);
      k = lower_bound(all(B), array<int, 2>({h, -1})) - B.begin();
      if (k != 0) {
         --k;
         if (mn[k] < w) {
            ans[ix] = pos[k];
         } 
      }      
   }
   for (int i : ans) {
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
   f(i,0,tt) test();   
   return 0;
}