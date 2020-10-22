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
   int ans = 0,c = 1;
   for(auto &e : s){
      ans += (e-'0')*c;
      c *= 10;
   }
   return ans;
}

int cnt(string s){
   int r = 0;
   for(char c : s){
      r += (c-'0');
   }
   return r;
}

void test(){
   int n,s;
   cin >> n >> s;
   int sm = 0;
   string T = to_string(n);
   for(char c : T){
      sm += c-'0';
   }
   if(sm <= s){
      cout << "0\n";
      return;
   }
   int len = T.length();
   reverse(all(T));
   int chk = 1;
   // cout << T << '\n';
   for(int i = 0; i < T.size(); ++i){
      if(T[i] == '0'){
         continue;
      }
      T[i] = '0';
      int j = i+1;
      while(j < T.size() and T[j] == '9'){
         T[j] = '0';
         ++j;
      }
      if(j == T.size()){
         T += '1';
      }else{
         T[j]++;
      }
      string kk = T;
      // reverse(all(kk));
      if(cnt(kk) <= s){
         // cout << kk << '\n';
         int v = to_int(kk);
         int diff = v-n;
         int c = 100;
         while(c--){
            string R = to_string(n+diff);
            if(cnt(R) <= s){
               kk = R;
            }else{
               break;
            }
         }
         reverse(all(kk));
         v = to_int(kk);
         cout << v-n << '\n';
         return;
      }
      // cout << kk << '\n';
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
