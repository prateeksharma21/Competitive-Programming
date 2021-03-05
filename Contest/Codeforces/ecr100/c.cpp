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
   vector<array<int, 2>> A(n);
   for (auto &[x, y] : A) {
      cin >> x >> y;
   }
   A.push_back({int(1e12), 1});
   int mv = 0;
   int to_mv = 0;
   int prv = 0;
   int Time = 0;
   int rem = 0;
   vector<int> P = {0};
   vector<int> C;
   vector<int> R;
   for (int i = 0; i < n; ++i) {
      auto &[cx, cy] = A[i];
      int diff = cx - prv;
      diff = min(diff, rem);
      rem -= diff;
      int lst = P.back();
      lst += mv * diff;
      P.push_back(lst);
      if (Time <= cx) {
         int n_mv = cy;
         if (n_mv == to_mv) {
            mv = 0;
         } else if (n_mv > to_mv) {
            mv = 1;
         } else {
            mv = -1;
         }
         Time = cx + abs(to_mv - n_mv);
         rem = abs(to_mv - n_mv);
         to_mv = n_mv; 
      }
      R.push_back(rem);
      C.push_back(mv);
      prv = cx;
   }
   P.erase(P.begin());
   // debug(P);
   // debug(C);
   // debug(R);
   int ans = 0;
   for (int i = 0; i < n; ++i) {
      int req = A[i][1];
      int cur = P[i];
      int co = C[i];
      int rem = min(R[i], A[i + 1][0] - A[i][0]);
      int nxt = cur + co * rem;
      if (nxt < cur) swap(nxt, cur);
      // debug(req, cur, nxt);
      if (req >= cur and req <= nxt) {
         ++ans;
      }
   }
   cout << ans << '\n';
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