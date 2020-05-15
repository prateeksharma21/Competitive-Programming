#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ld = long double;
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   string s;
   cin >> s;
   ld sm1 = 0,sm2 = 0;
   f(i,0,n/2){
      if(s[i] != '?'){
         sm1 += (s[i]-'0');
      }else{
         sm1 += 4.5;
      }
   }
   f(i,n/2,n){
      if(s[i] != '?'){
         sm2 += (s[i]-'0');
      }else{
         sm2 += 4.5;
      }
   }
   if(sm1 == sm2){
      cout << "Bicarp\n";
   }else{
      cout << "Monocarp\n";
   }
   return 0;
} 