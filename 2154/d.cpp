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
  vector<set<ll>> v(n);
  loop(i, n) {
    ll x, y; cin >> x >> y;
    x--, y--;
    v[x].insert(y);
    v[y].insert(x);
  }

  vector<ll> d(n, M), vis(n, 0);
  map<ll, vector<ll>> mp;
  d[0] = 0;
  function<void(ll, ll)> dfs = [&](ll x, ll dd) {
    vis[x] = 1;
    for (auto adj : v[x]) {
      if (vis[adj]) continue;
      d[adj] = dd + 1;
      mp[dd + 1].push_back(adj);
      dfs(adj, dd + 1);
    }
    return;
    };

  dfs(0, 0);
  ll cur = 0;
  vector<ll> ans;
  for (int j = d[n - 1] + 1; j < n; j++) {
    for (auto x : mp[j]) {
      ans.push_back(x);
    }
  }
  for (int j = 0; j < d[n - 1]; j++) {

  }
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
