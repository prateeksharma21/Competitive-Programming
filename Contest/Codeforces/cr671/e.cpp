#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

void test(){
   int n;
   cin >> n;
   vector<int> F;
   set<int> fact;
   for(int i = 2; i*i <= n; ++i){
      if(n % i == 0) {
         F.push_back(i);
         fact.insert(i);
         if(n / i != i){
            fact.insert(n/i);
            F.push_back(n/i);
         }
      }
   }
   debug(F);
   if(F.size() == 2 and __gcd(F[0],F[1]) == 1){
      cout << F[0] << ' ' << F[1] << ' ' << n << '\n';
      cout << "1\n";
      return;
   }
   sort(all(F));
   int x = n;
   vector<pair<int, int>> fct;
   for(int i = 2; i*i <= x; ++i){
      fct.push_back({i,0});
      while(x % i == 0){
         x /= i;
         fct.back().second++;
      }
      if(fct.back().second == 0){
         fct.pop_back();
      }
   }
   if(x > 1){
      fct.push_back({x,1});
   }
   int sz = fct.size();
   if(sz == 1){
      for(int i : F){
         cout << i << ' ';
      }
      cout << n << '\n' << "0\n";
      return;
   }
   vector<int> final;
   vector<int> R;
   int cur = fct[0].first;
   x = cur;
   for(int j = 0; j < fct[0].second; ++j){
      R.push_back(cur);
      fact.erase(cur);
      cur *= x;
   }
   // debug(fct);

   for(int i = 1; i < sz; ++i){
      fact.erase(fct[i-1].first*fct[i].first);
      R.push_back(fct[i-1].first*fct[i].first);
      int cur = fct[i].first;
      int x = cur;
      for(int j = 0; j < fct[i].second; ++j){
         R.push_back(cur);
         fact.erase(cur);
         cur *= x;
      }
   }
   // debug(R);
   int p = 0;
   for(int i = 0; i < sz-1; ++i){
      for(int j = 0; j < fct[i].S; ++j){
         int x = R[p++];
         final.push_back(x);
         cout << x << ' ';
      }
      int cur = fct[i].first;
      vector<int> tmp;
      for(int i : fact){
         if(i%cur == 0){
            tmp.push_back(i);
         }
      }
      for(int i : tmp){
         final.push_back(i);
         cout << i << ' ';
         fact.erase(i);
      }
      int jjj = R[p++];
      final.push_back(jjj);
      cout << jjj << ' ';
   }
   for(int j = 0; j < fct[sz-1].S; ++j){
      int x = R[p++];
      final.push_back(x);
      cout << x << ' ';
   }
   assert(p == R.size());
   final.push_back(n);
   cout << n;
   assert(fact.empty());
   cout << "\n0\n";
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
