#include <iostream>
#include <vector>

using namespace std;

#define MAXN 1000100

long long X[MAXN];
long long Y[MAXN];

typedef pair<long long, long long> pll;

void conv_insert(int ii, vector<pll>& C, pll x) {
  /* Erase everything from the set that is dominated by this line.  If this line
   * overtakes you before you overtake your predecessor you'll never be at the
   * top so you get dropped. */
  while(C.size() - ii > 1) {
    int i = C.size() - 2;
    int j = C.size() - 1;
    if((C[j].second - C[i].second) / (C[i].first - C[j].first) <
       (C[j].second - x.second) / (x.first - C[j].first)) {
      C.resize(C.size() - 1);
    } else break;
  }
  C.push_back(x);
}

long long eval(pll v, int x) {
  return v.second + x * v.first;
}

int main() {
   int N, K;
   cin >> N >> K;
   for(int i = 0; i < N; i++) cin >> X[i];

   /* The basic idea is we can use dynamic programming to solve this problem to
   * get cost(i) = min((X[i] - X[j-1])^2 + cost(j)) for j > i and cost(N) = 0.
   * We split this up into:
   * cost(i) = X[i]^2 + min(-2X[i]X[j] + (X[j-1]^2 + cost(j)))
   * where the first term is the only thing that will vary with X[i], i.e., we
   * have lines.  So I just sweep from right to left and keep track of which 
   * line is cheapest by ordering lines by when they become the best option.
   */
   int ii = 0;
   vector<pll> C;

   /* Connect to end. */
   // C.push_back(make_pair(-2 * X[N - 1], X[N - 1] * X[N - 1]));

   for(int i = N - 1; ; i--) {
   /* Remove lines that are no longer of interest.  To be efficient we erase
    * from the front by just incrementing the head 'ii' index. */
   while((int)C.size() - ii > 1 && eval(C[ii], X[i]) > eval(C[ii + 1], X[i])) {
     ii++;
   }
   /* Compute v = cost(i) */
   long long v = K ;
   if (C.size())
      v += X[i] * X[i] + eval(C[ii], X[i]);
   // cout << v << ' ' << X[i] * X[i] << ' ' << eval(C[ii], X[i]) << '\n';
   if(i == 0) {
     cout << v << endl;
     break;
   }
   /* Add this new entry to our line set. Since it has the largest slope so
    * far it always belongs on the set somewhere. */
   conv_insert(ii, C, make_pair(-2 * X[i], v + X[i] * X[i]));
   }
}