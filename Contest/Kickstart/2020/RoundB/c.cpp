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
const int MOD = 1e9, N = 1e5 + 10; 

int match[N];
string s;

int solve1(int st,int en){
   int x = 0;
   f(i,st,en+1){
      if(match[i]){
         x += (s[i-1]-'0')*solve1(i+1,match[i]-1);
         x += MOD;
         x %= MOD;
         i = match[i];
      }else{
         if(s[i] == 'N') x--;
         if(s[i] == 'S') x++;
      }
      x += MOD;
      x %= MOD;
   }
   return x;
}

int solve2(int st,int en){
   int x = 0;
   f(i,st,en+1){
      if(match[i]){
         x += (s[i-1]-'0')*solve2(i+1,match[i]-1);
         x += MOD;
         x %= MOD;
         i = match[i];
      }else{
         if(s[i] == 'W') x--;
         if(s[i] == 'E') x++;
      }
      x += MOD;
      x %= MOD;
   }
   return x;  
}


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt;
   cin >> tt;
   f(_,1,tt+1){
      cout << "Case #" << _ << ": ";
      cin >> s;
      int x = 0,y = 0;
      int n = s.length();
      stack<int> st;
      f(i,0,n) match[i] = 0;
      f(i,0,n){
         if(s[i] == '('){
            st.push(i);
         }
         if(s[i] == ')'){
            int tp = st.top();
            match[tp] = i;
            st.pop();
         }
      }      
      cout << solve2(0,n-1)+1 << ' ' << solve1(0,n-1)+1 << '\n';
   }
   return 0;
}