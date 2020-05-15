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
   int A[3];
   f(i,0,3) cin >> A[i];
   sort(A,A+3);
   cout << min((A[0]+A[1]+A[2])/3,A[0]+A[1]);
   return 0;
} 