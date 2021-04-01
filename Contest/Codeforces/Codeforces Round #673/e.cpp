#ifdef Prateek
  #include "\Prateek.h"
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
const int MOD = 1e9+7, N =3e5 + 10; 

int n;
int cst[N][2];
int a[N];

void dfs(vector<int> v, int ind) {
   if(ind < 0 or v.empty()) return;
   vector<int> one,zero;
   for(auto &i : v) {
      if((a[i] >> ind) & 1) {
         one.push_back(i);
      } else {
         zero.push_back(i);
      }
   }
   int c = 0;
   for(int i : zero) {
      c += (upper_bound(all(one),i)-one.begin());
   }
   cst[ind][0] += c;
   cst[ind][1] += (int)one.size() * (int)zero.size() - c;
   dfs(zero, ind-1);
   dfs(one, ind-1);
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n;
   vector<int> v;
   for(int i = 0; i < n; ++i) {
      cin >> a[i];
      v.push_back(i);
   }
   dfs(v, 30);
   int x = 0;
   int tot = 0;
   for(int i = 30; i >= 0; --i) {
      if(cst[i][1] < cst[i][0]) {
         x ^= (1<<i);
      }
      tot += min(cst[i][1], cst[i][0]);
   }
   cout << tot << ' ' << x << '\n';
   return 0;
} 