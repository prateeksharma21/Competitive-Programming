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
   int n;string s;
   cin >> n >> s;
   vector<int> pre1(n+1),pre2(n+1);
   f(i,1,n+1){
      pre1[i] = pre1[i-1]+(s[i-1] == 'A');
      pre2[i] = pre2[i-1]+(s[i-1] == 'B');
   }
   int ans = min(pre1[n],pre2[n]);
   f(i,1,n+1){
      ans = min(ans,pre2[i]+pre1[n]-pre1[i]);
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