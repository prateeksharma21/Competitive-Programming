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
   string s;
   cin >> s;
   vector<int> C(26);
   f(i,0,n){
      if('a'<=s[i] and s[i]<='z'){
         C[s[i]-'a']++;
      }else{
         C[s[i]-'A']++;
      }
   }
   bool chk = 1;
   f(i,0,26){
      chk &= (C[i]!=0);
   }
   cout << ((chk)?"YES":"NO");
   return 0;
}