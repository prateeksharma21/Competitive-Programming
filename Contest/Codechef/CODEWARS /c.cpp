#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10; 
const int M = 5e5+100;
int cnt[2*M];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   f(i,0,n){
      int x,y;
      cin >> x >> y;
      cnt[x+M] += 1;
      cnt[y+M+1] -= 1;
   }
   int ans = 0;
   int cur = 0;
   f(i,0,2*M+100){
      cur += cnt[i];
      ans += cur;
      ans %= MOD;
   }
   cout << ans << '\n';
   return 0;
} 