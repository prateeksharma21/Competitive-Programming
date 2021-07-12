#include <bits/stdc++.h>
using namespace std;

#ifdef Prateek
   #include "Prateek.h"
#else
   #define debug(...) 21
#endif

#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e15+7, N = 1e5 + 10;





int to_int(string s){
   int ans = 0;
   for(char c : s) {
      ans = ans * 10 + (c - '0');
   }
   return ans;
}

int apply(int a, int b) {
   return (70 * (a + 45) % MOD + 40 * (b + 9) % MOD) * (130 * (a + 23) % MOD + 90 * (b + 7) % MOD) % MOD; 
}

int eval(string s) {
   vector<string> stk;
   int n = s.length();
   for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
         stk.push_back("(");
         continue;
      }
      if (s[i] == ')') {
         int v1 = to_int(stk.back());
         stk.pop_back();
         string op = stk.back();
         stk.pop_back();
         int v2 = to_int(stk.back());
         stk.pop_back();
         stk.pop_back();
         if (op == "+") {
            stk.push_back(to_string(v1 + v2));
         } else if (op == "*") {
            stk.push_back(to_string(v1 * v2));
         } else {
            stk.push_back(to_string(apply(v1, v2)));
         }
         continue;
      }
      if (s[i] >= '0' and s[i] <= '9') {
         int j = i;
         string v = "";
         while (s[j] >= '0' and s[j] <= '9') {
            v += s[j];
            ++j;
         }
         stk.push_back(v);
         i = j - 1;
         continue;
      }
      string tmp = "";
      tmp += s[i];
      stk.push_back(tmp);
   }
   return to_int(stk.back());
}

void Solve() {
   int n;
   cin >> n;
   vector<string> s(n);
   vector<int> res;
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
      res.push_back(eval(s[i]));
   }
   vector<int> ans(n);
   int c = 1;
   for (int i = 0; i < n; ++i) {
      if (ans[i] == 0) {
         ans[i] = c;
         for (int j = i + 1; j < n; ++j) {
            if (res[j] == res[i]) {
               ans[j] = c;
            }
         }
         ++c;
      }
      cout << ans[i] << ' ';
   }
   cout << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      cout << "Case #" << t << ": ";
      Solve();
   }
   return 0;
}