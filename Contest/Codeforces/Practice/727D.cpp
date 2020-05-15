#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define f(i,x,n) for(ll i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define int ll

template < typename T > using indexed_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;

using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
 
const double PI = acos(-1);
const ll LINF = LLONG_MAX;
const int MOD = 1e9+7, INF = INT_MAX, N = 1e5 + 10;

#ifdef HOME
   #include "/home/prateek2112/print.cpp"
#else
   #define debug(...) 21
#endif

map<string,int> V;
int cnt[7];
vector<string> G[7];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   V["S"] = 1;
   V["M"] = 2;
   V["L"] = 3;
   V["XL"] = 4;
   V["XXL"] = 5;
   V["XXXL"] = 6;
   vector<string> K = {"","S","M","L","XL","XXL","XXXL"};
   vector<int> A(7);
   f(i,1,7){
      cin >> A[i];
   }
   int n;
   cin >> n;
   vector<string> S(n+1);
   vector<string> ANS(n+1,"");
   vector<pair<string, string>> s(n+1);
   f(i,1,n+1){
      cin >> S[i];
      int fin = -1;
      f(j,0,S[i].length()){
         if(S[i][j] == ','){
            fin = j;
         }
      }
      if(fin==-1){
         int v = V[S[i]];
         if(!A[v]){
            return cout << "NO\n",0;
         }
         ANS[i] = S[i];
         A[v]--;
      }else{
         string s1 = S[i].substr(0,fin),s2 = S[i].substr(fin+1);
         s[i]={s1,s2};
         cnt[min(V[s1],V[s2])]++;
      }
   }
   f(i,1,6){
      while(A[i] and cnt[i]){
         A[i]--;
         cnt[i]--;
         G[i].pb(K[i]);
      }
      while(A[i+1] and cnt[i]){
         A[i+1]--;
         cnt[i]--;
         G[i].pb(K[i+1]);
      }
      if(cnt[i]){
         return cout << "NO\n",0;
      }
   }
   cout << "YES\n";
   f(i,1,n+1){
      if(ANS[i] == ""){
         string s1 = s[i].F,s2 = s[i].S;
         cout << G[min(V[s1],V[s2])].back() << '\n';
         G[min(V[s1],V[s2])].pop_back();
      }else{
         cout << ANS[i] << '\n';
      }
   }
   return 0;
}