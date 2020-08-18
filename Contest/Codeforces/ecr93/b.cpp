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
   string s;
   cin >> s;
   int n = s.length();
   vector<int> R;
   for(int i = 0, j = 0; i < n; i = j){
      while(j < n and s[i] == s[j]) ++j;
      if(s[i] == '1'){
         R.push_back(j-i);
      }
   }
   sort(all(R),greater<int>());
   int ans = 0;
   for(int i = 0; i < R.size(); i += 2){
      ans += R[i];
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
