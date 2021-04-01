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
   vector<int> A(n),B(n);
   vector<pair<int, int>> R;
   f(i,0,n){
      cin >> A[i];
      R.pb({A[i],2});
   }
   f(i,0,n){
      cin >> B[i];
      R.pb({B[i],1});
   }
   sort(all(R));
   int c = 0,dn = 0;
   int ans = 0;
   while(c!=n){
      auto i = R.back();
      R.pop_back();
      if(i.S == 2){
         ans += i.F;
         c++;
         continue;
      } 
      if(dn != k){
         dn++;
         c++;
         ans += i.F;      
      }
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