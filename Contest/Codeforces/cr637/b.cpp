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
const int MOD = 1e9+7, N = 2000 + 10; 

int valid[N][N];
vector<string> A = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string S[N];
int n,k;

int diff(string s,string t){
   int ans = 0;
   f(i,0,7){
      if(s[i] == '0' and t[i] == '1') return -1;
      ans += (s[i]-t[i]);
   }
   return ans;
}

int check(int x,int y){
   if(x == n+1){
      return y == 0;
   }
   if(valid[x][y] != -1){
      return valid[x][y];
   }
   int &ans = valid[x][y];
   ans = 0;
   f(i,0,10){
      int d = diff(A[i],S[x]);
      if(d == -1 or d>y) continue;
      ans |= check(x+1,y-d);
   }
   return ans;
}

string find(int x,int y){
   if(x == n+1) return "";
   for(int j=9;j>=0;j--){
      int d = diff(A[j],S[x]);
      if(d == -1 or d > y or !check(x+1,y-d)) continue;
      return char('0'+j)+find(x+1,y-d);
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> k;
   memset(valid,-1,sizeof valid);
   f(i,1,n+1){
      cin >> S[i];
   }
   if(!check(1,k)){
      cout << "-1\n";
   }else{
      cout << find(1,k) << '\n';
   }
   return 0;
}