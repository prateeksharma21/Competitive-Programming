#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;
 
void test(){
   int n;
   cin >> n;
   vector<int> a(n);
   f(i,0,n){
      cin >> a[i];
   }
   vector<int> ans;
   sort(all(a));
   int l = 0, h = n-1;
   while(l<h){
      ans.pb(a[l]);
      ans.pb(a[h]);
      l++,h--;
   }
   if(l == h) ans.pb(a[l]);
   reverse(all(ans));
   f(i,0,n){
      cout << ans[i] << " \n"[i==n-1];
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