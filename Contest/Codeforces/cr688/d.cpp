#ifdef Prateek
  #include "\Prateek.h"
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
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int k;
   cin >> k;
   if (k & 1) {
      cout << "-1\n";
      return;
   }
   vector<int> A;
   while (k != 0) {
      int sm = 0;
      int pw = 1;
      int c = 0;
      while (sm + 2*pw <= k) {
         sm += 2*pw;
         pw *= 2;
         ++c;
      }
      k -= sm;
      A.push_back(1);
      for (int i = 0; i < c - 1; ++i) {
         A.push_back(0);
      }
   }
   cout << A.size() << '\n';
   for (int i : A) {
      cout << i << ' ';
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
