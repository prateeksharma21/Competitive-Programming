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
   int a[3];
   int sm = 0;
   for (int i = 0; i < 3; ++i) {
      cin >> a[i];
      sm += a[i];
   }
   int sh = sm / 9;
   sort(a, a + 3);
   if (a[0] < sh) {
      cout << "No\n";
      return;
   }
   if (sm % 9 == 0) {
      cout << "Yes\n";
   } else {
      cout << "No\n";
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