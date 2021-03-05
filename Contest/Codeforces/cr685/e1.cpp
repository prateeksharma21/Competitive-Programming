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
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) begin(c),end(c)
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   cout << "XOR 1 2" << endl;
   int a;
   cin >> a;
   int ff = a;
   cout << "AND 1 2" << endl;
   int b;
   cin >> b;
   int sm1 = (a + 2*b);

   cout << "XOR 2 3" << endl;
   cin >> a;
   int ss = a;
   cout << "AND 2 3" << endl;
   cin >> b;
   int sm2 = (a + 2*b);

   a = ff^ss;
   cout << "AND 1 3" << endl;
   cin >> b;
   int sm3 = (a + 2*b);
   
   vector<int> A(n);
   A[0] = (sm3 + (sm1 - sm2) ) / 2;
   A[1] = sm1-A[0];
   A[2] = sm3-A[0];

   for (int i = 3; i < n; ++i) {
      cout << "XOR 1 " << i + 1 << endl;
      int x;
      cin >> x;
      A[i] = x ^ A[0];
   }

   cout << "! ";
   for (int i : A) {
      cout << i << ' ';
   }
   cout << '\n';

   return 0;
} 