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
   string s;
   cin >> s;
   int n = s.length();
   vector<int> cnt(26);
   for (char c : s) {
      cnt[c - 'a']++;
   }
   for (int i = 0; i < 26; ++i) {
      if (cnt[i] == 1) {
         cout << char(i + 'a');
         --cnt[i];
         for (int j = 0; j < 26; ++j) {
            while(cnt[j]) {
               cout << char(j + 'a');
               --cnt[j];
            }
         }
         cout << '\n';
         return;
      }
   }
   sort(all(s));
   if (s.front() == s.back()) {
      cout << s << '\n';
      return;
   }
   string res = "";
   int st = -1;
   int done = 0;
   for (int i = 0; i < 26; ++i) {
      if (cnt[i]) {
         int re = n - 3;
         int re_c = cnt[i] - 2;
         if ((re + 1) / 2 >= re_c) {
            res += (i + 'a');
            res += (i + 'a');
            cnt[i] -= 2;
            st = i;
            break;
         }
         done = 1;
      }
   }
   assert(st != -1);
   string rem = "";
   for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < cnt[i]; ++j) {
         rem += (i + 'a');
      }
   }
   for (int i = 0; i < n - 2; ++i) {
      if (rem[i] == st + 'a') {
         int re = n - 2 - i - (i == 0);
         if ((re + 1) / 2 >= cnt[st]) {
            int c = 0;
            for (int i = 0; i < n - 2; ++i) {
               if (rem[i] - 'a' < st) {
                  res += rem[i];
                  c = 1;
                  continue;
               }
               if (rem[i] - 'a' == st) continue;
               if (cnt[st]) {
                  if (c) {
                     res += st + 'a';
                     --cnt[st];
                     --i;
                  } else {
                     res += rem[i];
                  }
                  c ^= 1;
               } else {
                  res += rem[i];
               }
            }
            if (cnt[st]) {
               res += (st + 'a');
               --cnt[st];
            }
            assert(cnt[st] == 0);
            cout << res << '\n';
            return;
         }
         break;
      }
   }
   string All = "";
   int c = 1;
   for (int i = n - 3; i >= 0; --i) {
      if (rem[i] - 'a' == st) continue;
      if (cnt[st]) {
         if (c) {
            All += st + 'a';
            --cnt[st];
            ++i;
         } else {
            All += rem[i];
         }
         c ^= 1;
      } else {
         All += rem[i];
      }
   }
   if (cnt[st]) {
      All +=(st + 'a');
      --cnt[st];
   }
   reverse(all(All));
   assert(cnt[st] == 0);
   res += All;
   cout << res << '\n';
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