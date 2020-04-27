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

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> A;
   map<int,bool> cnt;
   f(i,0,n){
      int x;
      cin >> x;
      if(!cnt[x]){
         A.pb(x);
      }
      cnt[x] = true;
   }
   sort(all(A));
   vector<int> diff;
   n = A.size();
   f(i,1,n){
      diff.pb(A[i]-A[i-1]);
   }
   sort(all(diff));
   vector<int> pre(n);
   f(i,1,n){
      pre[i] = pre[i-1]+diff[i-1];
   }
   int q;
   cin >> q;
   while(q--){
      int l,r;
      cin >> l >> r;
      int d = r-l;
      auto k = upper_bound(all(diff),d)-diff.begin();
      int ans = (A.size()-k)*(r-l+1);
      ans += pre[k];
      cout << ans << ' ';
   }
   return 0;
}