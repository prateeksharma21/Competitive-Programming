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
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 1; 

int seive[N];
vector<int> prime;
const int sq = 90;

void pre(int n){
   seive[0] = seive[1] = 1;
   for(int i = 2; i <= n; ++i){
      if(seive[i] == 0){
         prime.push_back(i);
         for(int j = i*i; j <= n; j += i){
            seive[j] = 1;
         }
      }
   }
}

int ask(char c,int x){
   cout << c << ' ' << x << endl;
   cin >> x;
   return x;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   pre(n);
   int sz = prime.size();
   int cur = n;
   int ans = 1;
   for(int i = 0; i < sz; i += sq){
      for(int j = i; j < min(sz,i+sq); ++j){
         int q = ask('B',prime[j]);
         cur -= q;
      }
      int now = ask('A',1);
      if(now > cur){
         cur = now;
         for(int j = i; j < min(sz,i+sq); ++j){
            int cnt = ask('A',prime[j]);
            int x = prime[j];
            while(cnt){
               ans *= prime[j];
               if(x*prime[j] > n) break;
               x *= prime[j];
               cnt = ask('A',x);
            }
         }
      }
   }
   cout << "C " << ans << endl;
   return 0;
}