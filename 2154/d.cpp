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
  vector<vector<ll>> v(n);
  loop(i, n - 1) {
    ll x, y; cin >> x >> y;
    x--, y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  vector<ll> par(n, 0), ch(n, 0), dep(n, 0);
  auto dfs = [&](auto self, ll c, ll p) -> void {
    if (p != -1) dep[c] = dep[p] + 1;
    par[c] = p;
    for (auto x : v[c]) {
      if (x == p) continue;

      self(self, x, c);
      ch[c]++;
    }
    };

  dfs(dfs, n - 1, -1);

  vector<vector<ll>> leaf(2);
  loop(i, n) {
    if (ch[i] == 0) {
      leaf[dep[i] % 2].push_back(i);
    }
  }

  vector<pair<ll, ll>> ans;
  ll cur = dep[0] & 1;
  loop(i, n - 1) {
    if (leaf[cur ^ 1].empty()) {
      ans.push_back({ 1, 1 });
      cur ^= 1;
    }

    ll nx = leaf[cur ^ 1].back();
    ans.push_back({ 2, nx });
    leaf[cur ^ 1].pop_back();

    ll p = par[nx];
    if (--ch[p] == 0) {
      leaf[dep[p] & 1].push_back(p);
    }

    ans.push_back({ 1,1 });
    cur ^= 1;
  }
  cout << ans.size() << endl;
  for (auto x : ans) {
    if (x.first == 1) cout << 1 << endl;
    else cout << "2 " << x.second + 1 << endl;
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
