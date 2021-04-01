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

int a[N];

int cal(vector<int> a) {
   int n = a.size();
   int r = 0;
   for (int i = 0, j = 0; i < n; i = j) {
      while (a[i] == a[j]) ++j;
      ++r;
   }
   return r;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   int prv = -1;
   int ans = 0;
   vector<int> lst;
   for (int i = 0, j = 0; i < n; i = j) {
      while (j < n and a[i] == a[j]) ++j;
      int c = j - i;
      if (c == 1) {
         lst.push_back(a[i]);
      } else {
         if (!lst.empty() and lst.back() == a[i]) {
            lst.pop_back();
         }
         if (a[i] == prv){
            if (lst.empty()) continue;
            int found = 0;
            int sz = lst.size();
            int K = lst.back();
            for (int i = sz - 2; i >= 0; --i) {
               if (lst[i] != prv and K != prv) found = 1; 
               K = lst[i];
            }
            ans += lst.size() + 1 + found;
         } else {
            ans += lst.size() + 2;
         }
         lst.clear();
         prv = a[i];
      }
   }
   ans += lst.size();
   cout << ans << '\n';
   return 0;
}