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
   vector<int> A(n),B(n);
   for(auto &e : A) cin >> e;
   for(auto &e : B) cin >> e;
   sort(all(A)),sort(all(B));
   int c = 0,a = 0,b = 0;
   while(!A.empty() or !B.empty()){
      if(!c){
         if(A.empty()){
            B.pop_back();
         }else if(B.empty()){
            a += A.back();
            A.pop_back();
         }else{
            if(A.back() >= B.back()){
               a += A.back();
               A.pop_back();
            }else{
               B.pop_back();
            }
         }
      }else{
         if(B.empty()){
            A.pop_back();
         }else if(A.empty()){
            b += B.back();
            B.pop_back();
         }else{
            if(B.back() >= A.back()){
               b += B.back();
               B.pop_back();
            }else{
               A.pop_back();
            }
         }
      }
      c ^= 1;
   }
   cout << a-b << '\n';
   return 0;
}