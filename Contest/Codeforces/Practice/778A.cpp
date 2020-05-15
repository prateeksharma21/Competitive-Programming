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
   string s;
   string t;
   cin >> s >> t;
   int n = s.length();
   vector<int> P(n);
   for(auto &e : P) cin >> e,e--;
   int l = 0,h = n;
   auto chk = [&](string s){
      int st = 0,i = 0;
      while(st<t.length() and i<s.length()){
         if(t[st] == s[i]){
            st++;
         }
         i++;
      }
      if(st == t.length()) return true;
      return false;
   };
   int ans = 0;
   while(l<=h){
      int mid = (l+h)/2;
      vector<int>  M(n);
      f(i,0,mid){
         M[P[i]] = 1;
      }
      string ns = "";
      f(i,0,n){
         if(!M[i]){
            ns += s[i];
         }
      }
      if(chk(ns)){
         ans = mid;
         l = mid+1;
      }else{
         h = mid-1;
      }
   }
   cout << ans << '\n';
   return 0;
} 