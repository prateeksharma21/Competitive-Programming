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

string first = "Ashish";
string second = "Utkarsh";

void test(){
   int d, k;
   cin >> d >> k;
   for (int i = 0; i <= (d / k) * k; i += k) {
      int x = i;
      int y = sqrt(d * d - x * x);
      y = (y / k) * k;
      if ((x + k) * (x + k) + y * y > d * d and (y + k) * (y + k) + x * x > d * d) {
         // int sm = (x + y) / k;
         if (x == y) {
            cout << second << '\n';
            return;
         }
      }
   }
   cout << first << '\n';
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
