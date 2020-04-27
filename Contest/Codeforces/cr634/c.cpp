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
   vector<int> a(n+1),cnt(n+1);
   f(i,1,n+1){
      cin >> a[i];
      cnt[a[i]]++;
   }   
   int el = 0;
   int mx = 0;
   f(i,1,n+1){
      if(mx<cnt[i]){
         mx = cnt[i];
         el  =i;
      }
   }
   int cn = 0;
   vector<int> done(n+1);
   f(i,1,n+1){
      if(el != a[i] and !done[a[i]]){
         cn++;
         done[a[i]] = 1;
      }
   }
   if(cn < mx){
      cn++;
      mx--;
   }
   cout << min(mx,cn) << '\n';
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
