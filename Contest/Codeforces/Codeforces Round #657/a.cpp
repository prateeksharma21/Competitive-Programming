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

const string r = "abacaba";

void test(){
   int n;
   string s;
   cin >> n >> s;
   if(n < 7){
      cout << "NO\n";
      return;
   }
   int cnt = 0;
   f(i,0,n-7+1){
      if(s.substr(i,7) == r){
         cnt++;
      }
   }
   if(cnt > 1){
      cout << "NO\n";
      return;
   }
   debug(cnt);
   if(cnt == 1){
      f(i,0,n){
         if(s[i] == '?'){
            s[i] = 'z';
         }
      }
      cout << "YES\n";
      cout << s << '\n';
      return;
   }else{
      f(i,0,n-7+1){
         string tt = s.substr(i,7);
         int c = 0;
         f(j,0,7){
            if(tt[j] == '?') c++;
            else c += (tt[j] == r[j]);
         }
         debug(c);
         if(c == 7){
            string s_n = s;
            f(j,i,i+7){
               s_n[j] = r[j-i];
            }
            debug(s_n);
            int v = 0;
            f(j,0,n-7+1){
               if(s_n.substr(j,7) == r){
                  v++;
               }
            }
            if(v == 1){
               cout << "YES\n";
               f(j,0,n){
                  if(s_n[j] == '?'){
                     s_n[j] = 'z';
                  }
               }
               cout << s_n << '\n';
               return;
            }
         }
      }
   }
   cout << "NO\n";
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
