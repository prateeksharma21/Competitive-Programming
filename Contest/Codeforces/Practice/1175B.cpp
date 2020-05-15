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
const int MX = (1ll<<32)-1;

int C[101];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   int x = 0;
   vector<int> A;
   while(n--){
      string s;
      cin >> s;
      if(s.front() == 'a'){
         int v = 1;
         f(i,2,101){
            f(j,0,C[i]){
               v *= i;
               if(v > MX){
                  return cout << "OVERFLOW!!!\n",0;
               }
            }
         }
         x+=v;
         if(x > MX){
            return cout << "OVERFLOW!!!\n",0;
         }
      }else if(s.front() == 'f'){
         int x; cin >> x;
         A.pb(x);
         C[x]++;
      }else{
         C[A.back()]--;
         A.pop_back();
      }
   }
   cout << x << '\n';
   return 0;
} 