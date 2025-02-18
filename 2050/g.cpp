#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;

void solve()
{
  int n; cin >> n;
  vector<vector<ll>> adj(n);
  loop(i, n - 1) {
    int x, y; cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<pair<ll, ll>> dp(n);

  function<void(int, int)> dfs = [&](int u, int par) {
    dp[u].first = adj[u].size();
    ll m1 = -1, m2 = -1;
    for (auto v : adj[u]) {
      if (v == par) continue;
      dfs(v, u);
      dp[u].first = max(dp[u].first, dp[v].first + (int)adj[u].size() - 2);
      m2 = max(m2, dp[v].first);
      if (m1 < m2) swap(m1, m2);
    }
    dp[u].second = dp[u].first;
    if (m2 != -1) {
      dp[u].second = m1 + m2 + adj[u].size() - 4;
    }
    };

  dfs(0, 0);
  ll ans = 0;
  loop(i, n) ans = max(ans, max(dp[i].first, dp[i].second));
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
