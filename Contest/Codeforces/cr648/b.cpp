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
   vector<int> A(n),B(n);
   int cnt = 0;
   f(i,0,n){
      cin >> A[i];
   }
   f(i,0,n){
      cin >> B[i];
      cnt += B[i];
   }
   if(is_sorted(all(A))){
      cout << "YES\n";
      return;
   }
   if(cnt == n or cnt == 0){
      cout << "NO\n";
   }else{
      cout << "YES\n";
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