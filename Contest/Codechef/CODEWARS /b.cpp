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
   vector<int> A(n);
   f(i,0,n){
      cin >> A[i];
   }
   int m;
   cin >> m;
   map<int,bool> cnt;
   vector<int> B(m);
   f(i,0,m){
      cin >> B[i];
      cnt[B[i]] = true;
   }
   vector<bool> a(n);
   f(i,0,n){
      a[i] = cnt[A[i]];
   }
   int ans = 0;
   for(int i=0,j=0;i<n;i=j){
      j = i;
      while(j<n and a[j] == true){
         j++;
      }
      if(j!=i) ans++;
      else j++;
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
