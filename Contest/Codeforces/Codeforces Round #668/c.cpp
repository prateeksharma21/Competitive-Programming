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
   int n,k;
   cin >> n >> k;
   string s;
   cin >> s;
   set<char> S[k];
   for(int i = 0; i < n; ++i){
      if(s[i] == '?') continue;
      S[i%k].insert(s[i]);
      if(S[i%k].size() > 1){
         cout << "NO\n";
         return;
      }
   }
   int c[2] = {0,0};
   int rem = 0;
   for(int i = 0; i < k; ++i){
      if(!S[i].empty()){
         char ff = *S[i].begin();
         c[ff-'0']++;
      }
   }
   if(c[1] <= k/2 and c[0] <= k/2){
      cout << "YES\n";
   }else{
      cout << "NO\n";
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
