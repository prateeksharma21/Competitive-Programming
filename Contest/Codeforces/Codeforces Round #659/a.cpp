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

// a
// aa
// aaaa
// aaaa
// aa

// aaaaa
// aaaaa
// aaa

void test(){
   int n;
   cin >> n;
   vector<int> a(n);
   f(i,0,n){
      cin >> a[i];
   }
   vector<string> R(n+1);
   f(i,0,n+1){
      R[i] = string(51,'a');
   }
   f(i,0,n){
      f(j,0,a[i]){
         R[i+1][j] = R[i][j];
      }
      f(j,a[i],51){
         char req = R[i][j];
         if(R[i][j] == 'z'){
            req--;
         }else{
            req++;
         }
         R[i+1][j] = req;
      }
   }
   f(i,0,n+1){
      cout << R[i] << '\n';
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
