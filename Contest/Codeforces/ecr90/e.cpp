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

int to_int(string s){
   reverse(all(s));
   if(s == " ") return 0;
   int ans = 0,c = 1;
   for(auto &e : s){
      ans += (e-'0')*c;
      c *= 10;
   }
   return ans;
}

void test(){
   int n,k;
   cin >> n >> k;
   k++;
   int res = LLONG_MAX;
   f(st,0,10){
      int cur = st;
      int sm = 0;
      int ff = 0, ss = 0;
      int chk = 0;
      f(j,0,k){
         sm += cur;
         if(!chk){
            ++ff;
         }else{
            ++ss;
         }
         cur++;
         cur %= 10;
         if(cur == 0) chk = 1;
      }
      if(chk){
         f(p,0,9){
            int val = ff*p+ss*(p+1);
            int req = n-(sm+val);
            if(req < 0 or req % k != 0) continue;
            req /= k;
            int cnt9 = req/9;
            req -= cnt9*9;
            string ans = "";
            ans += (req+'0');
            f(i,0,cnt9){
               ans += '9';
            }
            ans += (p+'0');
            ans += (st+'0');
            res = min(res,to_int(ans));
         }
         int cnt = 1;
         while(1){
            int val = cnt*9*ff;
            int req = n-(sm+val);
            if(req < 0) break;
            f(tt,0,10){
               if(tt*ff+(tt+1)*ss == req){
                  string ans = "";
                  ans += (tt+'0');
                  f(j,0,cnt){
                     ans += '9';
                  }
                  ans += (st+'0');
                  res = min(res,to_int(ans));
               }
            }
            cnt++;
         }
      }else{
         int req = n-sm;
         if(!(req < 0 or req %k != 0)){
            req /= k;
            int cnt9 = req/9;
            req -= cnt9*9;
            string ans = "";
            ans += (req + '0');
            f(i,0,cnt9) ans += '9';
            ans += (st+'0');
            res = min(res,to_int(ans));
         }
      }
   }
   if(res == LLONG_MAX){
      cout << "-1\n";
   }else{
      cout << res << '\n';
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
