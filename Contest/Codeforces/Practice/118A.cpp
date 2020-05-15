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

vector<char> A = {'a','e','i','o','u','y','A','E','I','O','U','Y'};

bool V(char c){
   for(auto &e : A){
      if(e == c) return true;
   }
   return false;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   string s;
   cin >> s;
   for(auto &e : s){
      if(V(e)) continue;
      cout << '.';
      if(e>='A' and e<='Z'){
         cout << char(e-'A'+'a');
      }else{
         cout << e;
      }
   }
   return 0;
}