#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 10;

void solve()
{
  ll n; cin >> n;
  map<ll, vector<ll>> adj;
  loop(i, n - 1) {
    ll x, y; cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  ll ans = 0, mx = -1, id = -1, c = 0;
  vector<ll> can;
  for (auto [fs, se] : adj) {
    ll si = se.size();
    if (si == n - 1) {
      cout << 0 << endl; return;
    }
    if (mx < si) id = fs;
    mx = max(mx, si);
    if (si == 1) c++;
  }
  for (auto [fs, se] : adj) {
    ll si = se.size();
    if (si == mx) can.push_back(fs);
  }
  ll mxleaf = 0;
  loop1(x, n) {
    ll leaf = 0;
    for (auto y : adj[x]) {
      if (adj[y].size() == 1) leaf++;
    }
    mxleaf = max(leaf, mxleaf);
  }
  // cout << leaf << " ";
  ans = c - mxleaf;
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
