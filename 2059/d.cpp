#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 1;

void solve()
{
  ll n, s1, s2; cin >> n >> s1 >> s2;
  s1--, s2--;
  ll m1; cin >> m1;
  vector<vector<ll>> g1(n), g2(n);
  vector<ll> good(n);
  set<pair<ll, ll>> edg;
  loop(i, m1) {
    ll x, y; cin >> x >> y;
    x--, y--;
    if (x > y) swap(x, y);
    edg.insert({ y, x });
    g1[x].push_back(y);
    g1[y].push_back(x);
  }
  ll m2; cin >> m2;
  loop(i, m2) {
    ll x, y; cin >> x >> y;
    x--, y--;
    if (x > y) swap(x, y);
    if (edg.find({ y, x }) != edg.end()) {
      good[x] = true, good[y] = true;
    }
    g2[x].push_back(y);
    g2[y].push_back(x);
  }

  vector<vector<ll>> d(n, vector<ll>(n, M));
  d[s1][s2] = 0;
  set<pair<ll, pair<ll, ll>>> st;
  st.insert({ 0, {s1, s2} });
  while (!st.empty()) {
    auto [v, u] = st.begin()->second;
    st.erase(st.begin());
    for (auto x : g1[v]) {
      for (auto y : g2[u]) {
        ll w = abs(x - y);
        if (d[x][y] > d[v][u] + w) {
          st.erase({ d[x][y], {x, y} });
          d[x][y] = d[v][u] + w;
          st.insert({ d[x][y], {x, y} });
        }
      }
    }
  }

  ll ans = M;
  loop(i, n) {
    if (!good[i]) continue;
    ans = min(ans, d[i][i]);
  }
  if (ans == M) {
    ans = -1;
  }
  cout << ans << endl;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
