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
   int n,x;
   cin >> n >> x;
   vector<int> A(n);
   int c0 = 0,c1 = 0;
   f(i,0,n){
      cin >> A[i];
      if(A[i] & 1){
         A[i] = 1;
         c1++;
      }else{
         A[i] = 0;
         c0++;
      }
   }
   f(i,1,c1+1){
      int take = i;
      if(take>x) break;
      int rem = x-i;
      if(rem<=c0){
         cout << "YES\n";
         return;
      }
      i++;
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
