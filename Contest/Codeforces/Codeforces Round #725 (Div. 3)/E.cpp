#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;

int count(string s) {
   int n = s.length();
   int ans = 0;
   for (int i = 0; i + 3 < n; ++i) {
      ans += s.substr(i, 4) == "haha";
   }
   return ans;
}

vector<string> split(string s) {
   vector<string> res;
   string cur;
   for (char c : s) {
      if (c == ' ') {
         res.push_back(cur);
         cur = "";
      } else {
         cur += c;
      }
   }
   res.push_back(cur);
   return res;
}

void test(int t){
   int n;
   cin >> n;
   vector<string> s(n);
   vector<vector<string>> a(n);
   debug(n);
   for (int i = 0; i < n; ++i) {
      getline(cin, s[i]);
      if (s[i].length() == 0) {
         --i;
         continue;
      }
      a[i] = split(s[i]);
   }

   // debug(a);

   vector<int> dp(n, -1);
   vector<string> lst(n), fst(n);
   vector<int> visL(n), visF(n);
   for (int i = 0; i < n; ++i) {
      lst[i] = string(4, ' ');
      fst[i] = string(4, ' ');
   }


   function<void(int)> getLast = [&](int x) {
      if (visL[x]) return;
      visL[x] = 1;
      if (a[x].size() == 3) {
         string k = a[x][2];
         reverse(all(k));
         while (k.length() > 4) k.pop_back();
         reverse(all(k));
         lst[x] = k;         
      } else {
         string f = a[x][2], s = a[x][4];
         int fi = -1, si = -1;
         for (int i = x - 1; i >= 0; --i) {
            if (a[i][0] == f) {
               fi = i;
               break;
            }
         }
         for (int i = x - 1; i >= 0; --i) {
            if (a[i][0] == s) {
               si = i;
               break;
            }
         }
         getLast(fi);
         getLast(si);
         string k = lst[fi] + lst[si];
         reverse(all(k));
         while (k.length() > 4) k.pop_back();
         reverse(all(k));
         lst[x] = k;
      }
   };

   function<void(int)> getFirst = [&](int x) {
      if (visF[x]) return;
      visF[x] = 1;
      if (a[x].size() == 3) {
         string k = a[x][2];
         while (k.length() > 4) k.pop_back();
         fst[x] = k;
      } else {
         string f = a[x][2], s = a[x][4];
         int fi = -1, si = -1;
         for (int i = x - 1; i >= 0; --i) {
            if (a[i][0] == f) {
               fi = i;
               break;
            }
         }
         for (int i = x - 1; i >= 0; --i) {
            if (a[i][0] == s) {
               si = i;
               break;
            }
         }
         getFirst(fi);
         getFirst(si);
         string k = fst[fi] + fst[si];
         while (k.length() > 4) k.pop_back();
         fst[x] = k;
      }
   };

   function<int(int)> dfs = [&](int x) {
      int &ans = dp[x];
      if (ans != -1) return ans;
      if (a[x].size() == 3) {
         string k = a[x][2];
         dp[x] = count(k);
      } else {
         string f = a[x][2], s = a[x][4];
         int fi = -1, si = -1;
         for (int i = x - 1; i >= 0; --i) {
            if (a[i][0] == f) {
               fi = i;
               break;
            }
         }
         for (int i = x - 1; i >= 0; --i) {
            if (a[i][0] == s) {
               si = i;
               break;
            }
         }
         getLast(fi);
         getFirst(si);
         dp[x] = dfs(fi) + dfs(si);
         string a = lst[fi], b = fst[si];
         while (a.length() < 4) {
            a = " " + a;
         }
         while (b.length() < 4) {
            b += ' ';
         }
         string k = a + b;
         for (int i = 1; i <= 3; ++i) {
            if (k.substr(i, 4) == "haha") {
               ++dp[x];
            }
         }
      }
      return dp[x];
   };

   cout << dfs(n - 1) << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test(t);
   }
   return 0;
}