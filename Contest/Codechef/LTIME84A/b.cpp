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
   string a,b;
   cin >> a >> b;
   f(i,0,n){
      if(a[i]<b[i]){
         cout << "-1\n";
         return;
      }
   }
   vector<set<int>> R;
   for(char c = 'z'; c >= 'a'; c--){
      set<int> P;
      f(i,0,n){
         if(b[i] == c){
            P.insert(i);
         }
      }
      int chk = 0;
      for(auto &i : P){
         if(a[i] != c){
            chk = 1;
            break;
         }
      }
      if(!chk) continue;
      debug(c);
      chk = 0;
      f(i,0,n){
         if(a[i] == c){
            chk = 1;
            P.insert(i);
         }
      }
      debug(chk);
      if(!chk){
         cout << "-1\n";
         return;
      }
      R.pb(P);
   }
   cout << R.size() << '\n';
   for(auto &e : R){
      cout << e.size() << ' ';
      for(auto &r : e){
         cout << r << ' ';
      }
      cout << '\n';
   }
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
