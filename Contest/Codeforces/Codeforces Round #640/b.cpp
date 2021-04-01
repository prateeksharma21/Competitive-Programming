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
 
bool Even(int n,int k){
   vector<int> A;
   int sm = 0;
   f(i,0,k){
      A.pb(2);
      sm += 2;
   }
   if(sm > n){
      return false;
   }
   if((n-sm)&1){
      return false;
   }else{
      cout << "YES\n";
      A.back() += (n-sm);
      for(auto &e : A) cout << e << ' ';
      cout << '\n';
      return true;
   }
}

bool Odd(int n,int k){
   vector<int> A;
   int sm = k;
   f(i,0,k){
      A.pb(1);
   }
   if(sm>n){
      return false;
   }
   if((n-sm)&1){
      return false;
   }else{
      cout << "YES\n";
      A.back() += (n-sm);
      for(auto &e : A) cout << e << ' ';
      cout << '\n';
      return true;
   }
}

void test(){
   int n,k;
   cin >> n >> k;
   if(Even(n,k)){
      return;
   }
   if(Odd(n,k)){
      return;
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
