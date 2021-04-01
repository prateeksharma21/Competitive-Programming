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

set<int> s;

void find (vector<int> &A) {
   int mx = 0, mn = 1e9;
   int sm = 0;
   for (int &i : A) {
      mx = max(mx, i);
      mn = min(mn, i);
      sm += i;
   }
   int mid = (mx + mn) / 2;
   s.insert(sm);
   vector<int> ff, ss;
   for (int &i : A) {
      if (i <= mid) {
         ff.push_back(i);
      } else {
         ss.push_back(i);
      }
   }
   if (ff.empty() or ss.empty()) return;
   find (ff);
   find (ss);
} 

void test(){
   int n, q;
   s.clear();
   cin >> n >> q;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   find(a);
   while (q--) {
      int x;
      cin >> x;
      if (s.count(x)) {
         cout << "Yes\n";
      } else {
         cout << "No\n";
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