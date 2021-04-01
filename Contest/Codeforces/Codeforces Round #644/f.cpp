#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;
 
#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif


void test(){
   int n,m;
   cin >> n >> m;
   vector<string> P;
   vector<string> s(n);
   f(i,0,n){
      cin >> s[i];
      f(j,0,m){
         char c = s[i][j];
         s[i][j] = '?';
         P.pb(s[i]);
         s[i][j] = c;
      }
   }

   auto chk = [&](string &a){
      f(i,0,n){
         int diff = 0;
         f(j,0,m){
            if(s[i][j]!=a[j]) diff++;
         }
         if(diff>1) return false;
      }
      return true;
   };

   for(auto &e : P){
      int pos = -1;
      string ans = e;
      f(i,0,m){
         if(ans[i] == '?'){
            pos = i;
            break;
         }
      }
      for(char c = 'a';c<='z';c++){
         ans[pos] = c;
         if(chk(ans)){
            cout << ans << '\n';
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
