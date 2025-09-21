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
  int n; cin >> n;
  vector<vector<ll>> g(n), h(n);
  vector<ll> deg(n, 0);

  loop(i, n - 1) {
    ll u, v, x, y;
    cin >> u >> v >> x >> y; u--, v--;
    if (x > y) {
      deg[u]++;
      g[u].push_back(v);
      h[v].push_back(u);
    }
    else {
      deg[v]++;
      g[v].push_back(u);
      h[u].push_back(v);
    }
  }

  queue<ll> q;
  loop(i, n) if (deg[i] == 0) q.push(i);

  vector<ll> ans(n);
  loop(i, n) {
    auto f = q.front(); q.pop();
    ans[f] = i + 1;

    for (auto x : h[f]) {
      deg[x]--;
      if (deg[x] == 0) {
        q.push(x);
      }
    }
  }

  for (auto x : ans) cout << x << " ";
  cout << endl;
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
