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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n), c(m);
	for (int &i : a) cin >> i;
	for (int &i : b) cin >> i;
	for (int &i : c) cin >> i;
	set<int> fix[n + 1];
	if (find(all(b), c.back()) == b.end()) {
		cout << "NO\n";
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) {
			fix[b[i]].insert(i);
		}
	}
	vector<int> done;
	vector<int> ans(m);
	int i = m - 1;
	if (fix[c.back()].empty()) {
		--i;
		for (int j = 0; j < n; ++j) {
			if (b[j] == c.back()) {
				done.push_back(j);
				ans.back() = j;
				break;
			}
		}
	}

	for ( ; i >= 0; --i) {
		if (fix[c[i]].empty()) {
			ans[i] = done.back();
		} else {
			int k = *fix[c[i]].begin();
			ans[i] = k;
			fix[c[i]].erase(fix[c[i]].begin());
			done.push_back(k);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!fix[i].empty()) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for (int i : ans) {
		cout << i + 1 << ' ';
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
      test();
	}
	return 0;
}