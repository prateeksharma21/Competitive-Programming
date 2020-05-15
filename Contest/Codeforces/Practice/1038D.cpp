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
   vector<int> A(n);
   int pos=0,neg=0;
   int ans = 0;
   int mn = 1e18;
   f(i,0,n){
      cin >> A[i];
      mn = min(mn,abs(A[i]));
      pos |= (A[i]>=0);
      neg |= (A[i]<=0);
      ans += abs(A[i]);
   }
   if(n == 1) return cout << A.front(),0;
   if(pos and neg){
      cout << ans << '\n';
   }else{
      cout << ans-2*mn << '\n';
   }
   return 0;
}