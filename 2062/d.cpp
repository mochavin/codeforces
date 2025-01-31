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
  ll n; cin >> n;
  vector<pair<ll, ll>> v(n);
  vector<vector<ll>> edge(n);
  vector<ll> a(n);
  loop(i, n) {
    // l r
    cin >> v[i].first >> v[i].second;
  }
  loop(i, n - 1) {
    ll x, y; cin >> x >> y;
    x--, y--;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }

  ll ans = 0;
  function<void(ll)> dfs = [&](ll u) {
    ll mx = v[u].first;
    for (auto x : edge[u]) {
      erase(edge[x], u);
      dfs(x);
      mx = max(mx, a[x]);
    }
    a[u] = min(mx, v[u].second);
    for (auto x : edge[u]) {
      ans += max(0ll, a[x] - a[u]);
    }
    };

  dfs(0);
  cout << ans + a[0] << endl;
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
