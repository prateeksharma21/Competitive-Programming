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
   int n,m;
   cin >> n >> m;
   vector<int> A(n);
   vector<int> B(m);
   f(i,0,n) cin >> A[i];
   f(i,0,m) cin >> B[i];
   sort(all(A));
   sort(all(B));
   int l = 1, h = 1e18;
   auto check = [&](int mid){
      int h = n-1;
      for(int i=m-1;i>=0;i--){
         if(h == -1) return true;
         int c = mid;
         while(h>=0 and c>0 and A[h]<=B[i]){
            h--;
            c--;
         }
      }
      if(h == -1) return true;
      return false;
   };
   int ans = m;
   while(l<=h){
      int mid = (l+h)>>1;
      if(check(mid)){
         ans = mid;
         h = mid-1;
      }else{
         l = mid+1;
      }
   }
   if(check(ans))
      cout << 2*ans-1 << '\n';
   else{
      cout << "-1\n";
   }
   return 0;
}