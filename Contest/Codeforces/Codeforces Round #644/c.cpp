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
   int n;
   cin >> n;
   vector<int> A(n);
   vector<int> cnt(110);
   int o = 0,ev = 0;
   for(auto &e : A){
      cin >> e;
      if(e&1) o++;
      else ev++;
      cnt[e]++;
   }
   if(o%2 == 0){
      cout << "YES\n";
      return;
   }
   debug(ev,o);
   f(i,1,101){
      if(cnt[i] and cnt[i+1]){
         cout << "YES\n";
         return;
      }
   }
   cout << "NO\n";
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
