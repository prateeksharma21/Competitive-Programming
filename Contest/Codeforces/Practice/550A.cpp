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
   int n = s.length();
   int C[2] = {0,0};
   f(i,0,n-1){
      if(s.substr(i,2) == "AB"){
         C[0]++;
      }
      if(s.substr(i,2) == "BA"){
         C[1]++;
      }
   }
   f(i,0,n-1){
      if(s.substr(i,2) == "AB"){
         if(i!=n-2){
            if(s[i+2] == 'A'){
               C[1]--;
            }
         }
         if(i!=0){
            if(s[i-1] == 'B'){
               C[1]--;
            }
         }
         if(C[1]){
            cout << "YES\n";
            return 0;
         }
         if(i!=n-2){
            if(s[i+2] == 'A'){
               C[1]++;
            }
         }
         if(i!=0){
            if(s[i-1] == 'B'){
               C[1]++;
            }
         }
      }
   }
   cout << "NO\n";
   return 0;
} 