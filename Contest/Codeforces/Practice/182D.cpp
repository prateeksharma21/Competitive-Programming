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
   string s,t;
   cin >> s >> t;

   auto find = [&](string s){
      map<string,int> A;
      int n = s.length();

      auto chk = [&](int in){
         string ns = "";
         f(i,0,in){
            ns += s[i];
         }
         string t = "";
         while(t.length()!=n){
            t += ns;
         }
         if(s == t){
            A[ns]++;
         }
      };

      for(int i=1;i*i<=n;i++){
         if(n%i == 0){
            chk(i);
            if(i!=n/i){
               chk(n/i);
            }
         }
      }

      return A;
   };


   map<string,int> A = find(s);
   map<string,int> B = find(t);

   int ans = 0;
   for(auto &e : A){
      ans += min(e.S,B[e.F]);
   }
   cout << ans << '\n';

   return 0;
} 