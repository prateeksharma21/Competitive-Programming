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
const int MOD = 1e9+7, N = 3e5 + 10; 

int A[N];
int S[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,k;
   cin >> n >> k;
   f(i,1,n+1) cin >> A[i];
   for(int i=n;i>=1;i--){
      S[i] = S[i+1]+A[i];
   }
   sort(S+2,S+n+1,greater<int>());
   int R = S[1],i = 2;
   k--;
   while(k--){
      R += S[i++];
   }
   cout << R << '\n';
   return 0;
} 