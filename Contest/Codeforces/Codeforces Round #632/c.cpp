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
   vector<int> a(n);
   f(i,0,n){
      cin >> a[i];
   }
   int cur = 0;
   multiset<int> s;
   map<int,int> lst;
   lst[0] = 1;
   map<int,int> rel;
   f(i,0,n){
      cur += a[i];
      if(lst[cur]){
         rel[lst[cur]-1] = i+1;
         s.insert(i);
      }
      lst[cur] = i+2;
   }
   // if(s.empty()){
   //    cout << n*(n+1)/2 << '\n';
   //    return 0;
   // }
   // for(auto &e : s){
   //    cout << e.F << ' ' << e.S << '\n';
   // }
   int ans = 0;
   f(i,0,n){
      if(a[i]){
         if(s.empty()){
            ans += n-i;
         }else{
            auto k = *s.begin();
            ans += k-i;
         }
      }
      if(rel[i]){
         s.erase(rel[i]-1);
      }
   }
   cout << ans << '\n';
   return 0;
}