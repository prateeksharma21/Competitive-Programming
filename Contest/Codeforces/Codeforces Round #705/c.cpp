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

void test(){
   int n, k;
   cin >> n >> k;
   string s;
   cin >> s;
   if (n % k) {
      cout << "-1\n";
      return;
   }
   vector<int> cnt(26);
   for (char i : s) {
      cnt[i - 'a']++;
   }
   int good = 1;
   for (int i = 0; i < 26; ++i) {
      good &= (cnt[i] % k == 0);
   }
   if (good) {
      cout << s << '\n';
      return;
   }
   int req = 0;
   for (int i = 0; i < 26; ++i) {
      req += (k - cnt[i] % k) % k;
   }
   for (int i = n - 1; i >= 0; --i) {
      req -= (k - cnt[s[i] - 'a'] % k) % k;
      --cnt[s[i] - 'a'];
      req += (k - cnt[s[i] - 'a'] % k) % k;
      for (int j = s[i] - 'a' + 1; j < 26; ++j) {
         int prv = req;
         req -= (k - cnt[j] % k) % k;
         ++cnt[j];
         req += (k - cnt[j] % k) % k;
         if (i + req + 1 <= n) {
            cout << s.substr(0, i) << char('a' + j);
            string t = "";
            for (int l = 0; l < 26; ++l) {
               cnt[l] = (k - cnt[l] % k) % k;
               while (cnt[l]--) {
                  t += l + 'a';
               }
            }
            while (t.size() + i + 1 < n) t += 'a';
            sort(all(t));
            cout << t << '\n';
            return;
         }
         --cnt[j];
         req = prv;
      }
   }
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}