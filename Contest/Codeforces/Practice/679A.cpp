#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 
#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   vector<int> A;
   auto is_prime = [&](int x){
      int c = 0;
      for(int i=2;i*i<=x;i++){
         c |= (x%i == 0);
      }
      return !c;
   };
   f(i,2,101){
      if(is_prime(i)){
         A.pb(i);
      }
   }
   int cnt = 0;
   f(i,0,20){
      cout << A[i] << endl;
      string s;
      cin >> s;
      cnt += (s == "yes");
   }
   if(cnt >= 2){
      cout << "prime\n";
   }else{
      cout << "composite\n";
   }
   return 0;
}