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
	vector<int> a(n);
	for (int &i : a) {
		cin >> i;
	}
	int cur = 1;
	while (true) {
		int i = 0;
		while (i < n - 1) {
			if (a[i] >= a[i + 1]) {
				++i;
			} else {
				a[i]++;
				break;
			}
		}
		if (i == n - 1) {
			cout << -1 << '\n';
			return;
		}
		if (cur == k) {
			cout << i + 1 << '\n';
			return;
		}
		++cur;
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