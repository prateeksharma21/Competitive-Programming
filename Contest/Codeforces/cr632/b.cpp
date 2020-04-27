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
   vector<int> a(n),b(n);
   map<int,int> cnt;
   f(i,0,n){
      cin >> a[i];
      cnt[a[i]]++;
   }
   f(i,0,n){
      cin >> b[i];
   }
   for(int i=n-1;i>=0;i--){
      cnt[a[i]]--;
      if(a[i] == b[i]) continue;
      if(a[i]<b[i]){
         if(!cnt[1]){
            cout << "NO\n";
            return;
         }
      }else{
         if(!cnt[-1]){
            cout << "NO\n";
            return;
         }
      }
   }
   cout << "YES\n";
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