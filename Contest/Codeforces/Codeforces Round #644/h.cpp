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
   int n,m;
   cin >> n >> m;
   vector<int> A;
   f(i,0,n){
      string s;
      cin >> s;
      int el = 0;
      reverse(all(s));
      f(j,0,m){
         if(s[j] == '1'){
            el += (1ll<<j);
         }
      }
      A.pb(el);
   }
   sort(all(A));
   int rem = (1ll<<m)-n;
   int mid = (rem+1)/2;
   int tot = 0;
   A.pb((1ll<<m)+1);
   debug(A,mid,rem);
   int res = -1;
   f(i,0,n+1){
      if(i){
         tot += A[i]-A[i-1]-1;
      }else{
         tot += A[i];
      }
      if(tot>=mid){
         if(i){
            tot -= (A[i]-A[i-1]-1);
            int left = mid-tot;
            res =  A[i-1]+left;
            break;
         }
         else{
            tot -= (A[i]);
            int left = mid-tot;
            res = left-1;
            break;
         }
      }
   }
   string ans = "";
   f(i,0,m){
      if((1ll<<i)&res){
         ans += '1';
      }else{
         ans += '0';
      }
   }
   reverse(all(ans));
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
