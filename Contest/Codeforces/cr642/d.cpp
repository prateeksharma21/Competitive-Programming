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
   vector<int> A(n+1);
   set<array<int,3>> seg;
   seg.insert({-n,1,n});
   int c = 1;
   auto push = [&](int l,int r){
      if(l<=r){
         seg.insert({-r+l-1,l,r});
      }
   };

   while(!seg.empty()){
      auto k = *seg.begin();
      seg.erase(k);
      int len = -k[0];
      int l = k[1],r = k[2];
      if(len & 1){
         A[(l+r)/2] = c++;
         push(l,(l+r)/2-1);
         push((l+r)/2+1,r);
      }else{
         int mid = (l+r-1)/2;
         A[mid] = c++;
         push(l,mid-1);
         push(mid+1,r);
      }
   }
   f(i,1,n+1){
      cout << A[i] << " \n"[i==n];
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