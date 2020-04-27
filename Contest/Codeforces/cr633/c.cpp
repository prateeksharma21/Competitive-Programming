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
 
string binary(int x){
   string s = "";
   while(x){
      s += (x%2+'0');
      x /= 2;
   }
   while(s.length()<2){
      s += '0';
   }
   if(s.length() & 1){
      s += '0';
   }
   reverse(all(s));
   return s;
}

int to_int(vector<string> a){
   reverse(all(a));
   string s = "";
   for(auto &e : a) s += e;
   reverse(all(s));
   int ans = 0;
   f(i,0,s.length()){
      ans += (1ll<<i)*(s[i]-'0');
   }
   return ans;
}

map<string,vector<string>> mp;

void test(){
   int n;
   cin >> n;
   if(n <= 3){
      cout << n << '\n';
      return;
   }
   int ff = n;
   if(n%3 == 0){
      ff -= 2;
   }else if(n%3 == 2){
      ff -= 1;
   }
   int c = 1;
   while(c<=ff){
      c *= 4;
   }
   c /= 4;
   ff -= c;
   ff = c+ff/3;
   // cout << ff << ' ' << c<< '\n';
   vector<int> el = {ff};
   string s = binary(ff);
   int l = s.length();
   vector<string> ss,tt;
   for(int i=l-2;i>=0;i-=2){
      string t = s.substr(i,2);
      // cout << t << '\n';
      // cout << "map " << mp[t][0] << ' ' << mp[t][1] << '\n';
      ss.pb(mp[t][0]);
      tt.pb(mp[t][1]);
   }
   el.pb(to_int(ss));
   el.pb(to_int(tt));
   // reverse(all(ss));
   // reverse(all(tt));
   // cout << s << '\n';
   // cout << ss << '\n';
   n--;
   cout << el[n%3] << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   mp["11"] = {"01","10"};
   mp["10"] = {"11","01"};
   mp["01"] = {"10","11"};
   mp["00"] = {"00","00"};
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}
