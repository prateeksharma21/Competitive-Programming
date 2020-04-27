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
   cin >> s;
   stack<char> S;
   int ans = 0;
   auto Pair = [&](char a,char b){
      if(a == '<' and b == '>') return true;
      if(a == '{'  and b == '}') return true;
      if(a == '(' and b == ')') return true;
      if(a == '[' and b == ']') return true;
      return false;
   };
   for(auto &c : s){
      if(c == '[' or c == '<' or c == '{' or c == '('){
         S.push(c);
      }else{
         if(S.empty()){
            cout << "Impossible\n";
            return 0;
         }
         char tp = S.top();
         S.pop();
         if(!Pair(tp,c)){
            ans++;
         }
      }
   }
   if(!S.empty()){
      cout << "Impossible\n";
      return 0;
   }
   cout << ans << '\n';
   return 0;
}