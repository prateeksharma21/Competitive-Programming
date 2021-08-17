#include <atcoder/modint>

#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  using Mint = atcoder::modint1000000007;

  int m, d;
  array<string, 2> s;
  vector<vector<vector<Mint>>> dp;
  vector<vector<vector<int>>> seen;

  void Read() {
    cin >> m >> d >> s[0] >> s[1]; 
  }
 
  void Solve() {
    Mint ans = Count(1);
    if (s[0] != "0") {
      Decrement(s[0]);
      debug(s);
      ans -= Count(0);
    }
    cout << ans.val() << '\n';
  }

  void Decrement(string &ss) {
    int p = int(ss.size()) - 1;
    while (ss[p] == '0') {
      ss[p] = '9';
      --p;
    }
    --ss[p];
    p = 0;
    while (p < int(ss.size()) && ss[p] == '0') {
      ++p;
    }
    ss = ss.substr(p);
    if (ss.empty()) {
      ss = "0";
    }
  }

  Mint Count(int p) {
    dp = vector(int(s[p].size()), vector(m, vector(3, Mint(0))));
    seen = vector(int(s[p].size()), vector(m, vector(3, 0)));
    return Get(0, 0, 1, p);
  }

  Mint Get(int ind, int mod, int comp, int p) {
    if (ind == int(s[p].size())) {
      return Mint(mod == 0 && comp <= 1);
    }
    auto &ans = dp[ind][mod][comp];
    auto &vis = seen[ind][mod][comp];
    if (!vis) {
      vis = true;
      if (ind != 0) {
        ans = Mint(mod == 0);
      }
      auto Update = [&](int dd) -> void {
        int orig = int(s[p][ind] - '0');
        int new_mod = ((10 * mod) % m + dd) % m;
        if (comp == 0 || comp == 2) {
          ans += Get(ind + 1, new_mod, comp, p);
        } else {
          int new_comp;
          if (dd < orig) {
            new_comp = 0;
          } else if (dd == orig) {
            new_comp = 1;
          } else {
            new_comp = 2;
          }
          ans += Get(ind + 1, new_mod, new_comp, p);
        }
      };
      if (ind & 1) {
        Update(d);
      } else {
        for (int dig = (ind == 0 ? 1 : 0); dig <= 9; ++dig) {
          if (dig != d) {
            Update(dig);
          }
        }
      }
    }
    return ans;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}