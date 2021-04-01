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
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n;
   cin >> n;
   int mx = 0;
   vector<int> A(n);
   for(int &i : A) {
      cin >> i;
      mx = max(mx, i);
   }
   for(int i = 0; i < n; ++i) {
      if(A[i] == mx) {
         if(i > 0 and A[i-1] != mx) {
            cout << i+1 << '\n';
            return;
         }
         if(i+1 < n and A[i+1] != mx) {
            cout << i+1 << '\n';
            return;
         }
      }
   }
   cout << "-1\n";
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
 