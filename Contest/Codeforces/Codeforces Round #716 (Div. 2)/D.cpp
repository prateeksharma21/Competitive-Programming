#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 3e5 + 10; 
const int block_size = 600;

int n, q;
int a[N];
int mx;
int cnt[N];
int cnt_mx[N];
int v;

void remove(int idx) {
   v = a[idx];
   cnt_mx[cnt[v]]--;
   if (cnt_mx[cnt[v]] == 0 and mx == cnt[v]) {
      mx = 0;
   }
   cnt[v]--;
   mx = max(mx, cnt[v]);
   if (cnt[v] != 0) {
      cnt_mx[cnt[v]]++;
   }
}

void add(int idx) {
   v = a[idx];
   if (cnt[v] != 0) {
      --cnt_mx[cnt[v]];
   }
   cnt[v]++;
   cnt_mx[cnt[v]]++;
   mx = max(mx, cnt[v]);
}


struct Query {
   int l, r, idx;
   bool operator<(Query other) const
   {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
   }
};

void mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    vector<int> fix(queries.size());
    sort(queries.begin(), queries.end());
    int cur_l = 0;
    int cur_r = -1;
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }

        int d = q.r - q.l + 1;
        if (mx <= (d + 1) / 2) {
            answers[q.idx] = 1;
        } else {
            answers[q.idx] = (2 * mx - d);
        }
    }
    for (int i = 0; i < queries.size(); ++i) {
      cout << answers[i] << '\n';
    }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> q;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   vector<Query> Q;
   for (int i = 0; i < q; ++i) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      Q.push_back({l, r, i});
   }
   mo_s_algorithm(Q);
   return 0;
}