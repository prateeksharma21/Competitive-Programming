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
   int mx = 0;
   vector<int> c(10);
   f(i,0,n){
      c[s[i]-'0']++;
      mx = max(mx,c[s[i]-'0']);
   }
   mx = max(mx,2ll);
   int ans = 0;
   vector<int> R;
   int cr = 2;
   while(cr <= n){
      R.pb(cr);
      cr += 2;
   }   

   f(i,0,10){
      f(j,0,10){
         int cur = 0;
         int cnt = 0;
         int c = 0;
         while(cur < n){
            if(c == 0){
               if(s[cur] == i+'0'){
                  c = 1;
                  cnt++;
               }
            }else{
               if(s[cur] == j+'0'){
                  c = 0;
                  cnt++;
               }
            }
            cur++;
         }
         mx = max(mx,2*(cnt/2));
      }
   }

   cout << n-mx << '\n';
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
