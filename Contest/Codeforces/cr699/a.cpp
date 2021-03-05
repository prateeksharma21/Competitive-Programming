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
	int x, y;
	cin >> x >> y;
	string s;
	map<char, int> cnt;
	cin >> s;
	int n = s.length();
	for (char c : s) {
		cnt[c]++;
	}
	int rU = 0, rD = 0;
	if (y > 0) {
		rU = y;
	} else {
		rD = -y;
	}
	int rL = 0, rR = 0;
	if (x > 0) {
		rR = x;
	} else {
		rL = -x;
	}
	if (cnt['L'] >= rL and cnt['R'] >= rR and cnt['U'] >= rU and cnt['D'] >= rD) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
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