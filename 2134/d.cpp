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
  vector<vector<ll>> v(n + 1);
  loop(i, n - 1) {
    ll x, y; cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  ll f = 1;
  // dari leaf
  queue<ll> q;
  loop1(i, n) {
    if (v[i].size() > 2) {
      f = 0;
    }
    else if (v[i].size() == 1)
      q.push(i);
  }
  if (n <= 2 || f) {
    cout << -1 << endl; return;
  }

  vector<ll> d(n + 1), par(n + 1, -1);
  auto bfs = [&](ll src) {
    fill(d.begin(), d.end(), -1);

    queue<ll> q;
    q.push(src);
    d[src] = 0;
    par[src] = -1;
    while (!q.empty()) {
      ll fr = q.front(); q.pop();
      for (auto x : v[fr]) {
        if (d[x] == -1) {
          d[x] = d[fr] + 1;
          par[x] = fr;
          q.push(x);
        }
      }
    }

    ll ans = 0, far = 0;
    loop1(i, n) if (d[i] > far) {
      far = d[i];
      ans = i;
    }
    return ans;
    };

  ll x = bfs(1);
  ll y = bfs(x);

  if (d[y] == n - 1) {
    cout << -1 << endl; return;
  }

  vector<ll> onD(n + 1, 0);
  while (y != -1) {
    onD[y] = 1;
    y = par[y];
  }

  loop1(i, n) {
    if (!onD[i]) continue;
    for (auto x : v[i]) {
      if (!onD[x]) {
        cout << par[i] << " " << i << " " << x << endl; return;
      }
    }
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
