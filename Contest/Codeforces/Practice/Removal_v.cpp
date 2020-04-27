#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;
 
int removeAlternate(int n) { 
    if (n == 1) 
        return 1; 
  
    if (n % 2 == 0) 
        return 2 * removeAlternate(n / 2) - 1; 
    else
        return 2 * removeAlternate(((n - 1) / 2)) + 1; 
} 

void test(){
   int n,k;
   cin >> n >> k;
   int pos = removeAlternate(n);
   // cout << pos << '\n';
   int st = (2*k)%n;
   if(st == 0) st = n;
   pos += st;
   pos %= n;
   if(pos == 0) pos = n;
   cout << pos << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}
