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

void test(){
   int n,k;
   cin >> n >> k;
   vector<vector<int>> S(k);
   f(i,0,k){
      int x; cin >> x;
      f(j,0,x){
         int y; cin >> y;
         S[i].push_back(y);
      }
   }
   cout << "? " << n << ' ';
   f(i,1,n+1){
      cout << i << ' ';
   }
   cout << endl;
   int MX;
   cin >> MX;

   auto query = [&](int l,int r){
      int sz = 0;
      f(i,l,r+1){
         sz += S[i].size();
      }
      cout << "? " << sz << ' ';
      f(i,l,r+1){
         for(auto &e : S[i]){
            cout << e << ' ';
         }
      }
      cout << endl;
      int R; cin >> R;
      return R;
   };

   int l = 0,r = k-1;
   while(l<r){
      int m = l+r>>1;
      if(query(l,m) == MX){
         r = m;
      }else{
         l = m+1;
      }
   }
   vector<int> C(n+1);
   for(auto &e : S[l]){
      C[e] = 1;
   }
   cout << "? "<< n-S[l].size() << ' ';
   f(i,1,n+1){
      if(!C[i]){
         cout << i << ' ';
      }
   }
   cout << endl;
   int MX2;
   cin >> MX2;
   cout << "! ";
   f(i,0,k){
      if(i == l){
         cout << MX2 << ' ';
      }else{
         cout << MX << ' ';
      }
   }
   cout << endl;
   string s; cin >> s;
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