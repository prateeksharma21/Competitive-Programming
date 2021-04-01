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
   int n,k;
   cin >> n >> k;
   string s;
   cin >> s;
   int tot = count(all(s),'1');
   if(tot == 0){
      cout << "0\n";
      return;
   }
   set<pair<int, int>> P[k];
   vector<int> C(k),V(k);
   vector<int> pre(n),suff(n);
   vector<int> Pre(n),cnt(n),one(n);
   f(i,0,n){
      if(i<k){
         Pre[i] = (s[i] == '0');
      }else{
         Pre[i] = Pre[i-k]+(s[i] == '0');
      }
      if(i){
         cnt[i] = cnt[i-1]+(s[i] == '1');
      }else{
         cnt[i] = (s[i] == '1');
      }
      C[i%k] += (s[i] == '1');
      V[i%k]++;
   }
   for(int i=n-1;i>=0;i--){
      suff[i] = tot-C[i%k]+V[i%k]-C[i%k];
      C[i%k] -= (s[i] == '1');
      V[i%k]--;
      P[i%k].insert({suff[i],i});
   }
   int ans = 1e18;
   f(i,0,n){
      auto it = *P[i%k].begin();
      int len = (it.S-i)/k+1;
      int zero = Pre[it.S]-((i>=k)?Pre[i-k]:0);
      int mv = zero+(i?cnt[i-1]:0)+cnt[n-1]-cnt[it.S];
      mv += cnt[it.S]-(i?cnt[i-1]:0)-(len-zero);
      ans = min(ans,mv);
      P[i%k].erase({suff[i],i});
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