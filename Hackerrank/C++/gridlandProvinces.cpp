#include <algorithm>
#include <functional>
#include <iostream>
#include <tuple>
#include <type_traits>
#include <unordered_set>
#include <utility>
using namespace std;

#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

const long N = 600, E = 3, M[E] = {26, 37, 73};
char a[2][N+1];
pair<long, long> pref[2][N+1][E], suff[2][N+1][E];
typedef unsigned long ulong;
typedef tuple<ulong, ulong, ulong> tuuu;

namespace std {
template<>
  struct hash<tuuu> {
    size_t operator()(const tuuu& x) const {
      return (get<0>(x) * 97 + get<1>(x)) * 97 + get<2>(x);
    }
  };
}

unordered_set<tuuu> vis;

#define F(x) do { REP(_j, E) h[_j] = h[_j]*M[_j]+x-'a'; } while (0)

void f(long n)
{
  REP(w, 2) {
    unsigned long g[E], h[E];
    fill_n(g, E, 1);
    fill_n(h, E, 0);
    REP(j, E)
      pref[w][n][j] = {1, 0};
    ROF(i, 0, n)
      REP(j, E) {
        h[j] = g[j]*(a[w][i]-'a')+h[j];
        g[j] *= M[j];
        pref[w][i][j] = {g[j], h[j]};
      }
    fill_n(g, E, 1);
    fill_n(h, E, 0);
    REP(j, E)
      suff[w][n][j] = {1, 0};
    ROF(i, 0, n)
      REP(j, E) {
        h[j] = M[j]*h[j]+(a[w][i]-'a');
        g[j] *= M[j];
        suff[w][i][j] = {g[j], h[j]};
      }
  }

  REP(i, n) {
    unsigned long h[E] = {};
    ROF(k, 0, i+1)
      F(a[0][k]);
    REP(k, i+1)
      F(a[1][k]);
    long w = 1;
    for (long j = i; ; ) {
      unsigned long th[E];
      copy_n(h, E, th);
      REP(k, E) {
        th[k] = pref[w][j+1][k].first*th[k]+pref[w][j+1][k].second;
        th[k] = suff[w^1][j+1][k].first*th[k]+suff[w^1][j+1][k].second;
      }
      vis.emplace(th[0], th[1], th[2]);
      if (++j >= n-1) break;
      F(a[w][j]);
      F(a[w^1][j]);
      w ^= 1;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  long cases, n;
  for (cin >> cases; cases--; ) {
    vis.clear();
    cin >> n >> a[0] >> a[1];
    f(n);
    swap_ranges(a[0], a[0]+n, a[1]);
    f(n);
    reverse(a[0], a[0]+n);
    reverse(a[1], a[1]+n);
    f(n);
    swap_ranges(a[0], a[0]+n, a[1]);
    f(n);
    cout << vis.size() << endl;
  }
}