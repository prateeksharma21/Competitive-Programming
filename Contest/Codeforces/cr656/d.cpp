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
   string s;
   cin >> s;
   
   vector<vector<int>> pre(n+1,vector<int>(26));
   f(i,0,n){
      pre[i+1] = pre[i];
      pre[i+1][s[i]-'a']++;
   }

   function<int(int,int,char)> dfs = [&](int st,int en,char c){
      if(en == st){
         return int(s[st-1] != c);
      }
      int m = (en-st+1)/2;
      int cnt1 = pre[m+st-1][c-'a']-pre[st-1][c-'a'];
      int cnt2 = pre[en][c-'a']-pre[m+st-1][c-'a'];
      cnt1 = m-cnt1;
      cnt2 = m-cnt2;
      return min(dfs(st,st+m-1,c+1)+cnt2,dfs(st+m,en,c+1)+cnt1);
   };

   cout << dfs(1,n,'a') << '\n';

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