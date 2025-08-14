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

ll mul(ll x, ll y) {
  return x * y % M;
}

ll binpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1) res = (res * x) % M;
    x = (x * x) % M;
    y /= 2;
  }
  return res;
}

ll bagi(ll x, ll y) {
  return (x * binpow(y, M - 2)) % M;
}

void solve()
{
  ll n, m; cin >> n >> m;

  vector<vector<pair<ll, ll>>> a(m + 1);
  vector<ll> dp(m + 1);
  dp[0] = 1;

  loop(i, n) {
    ll l, r, p, q; cin >> l >> r >> p >> q;
    a[r].push_back({ l - 1, bagi(p,q) });
    dp[0] = (dp[0] * bagi(q - p, q)) % M;
  }

  // cout << dp[0] << " ";

  for (int i = 1; i <= m; i++) {
    for (auto [l, p] : a[i]) {
      ll curr = dp[l];
      curr = (curr * p) % M;
      curr = bagi(curr, 1 - p + M);
      dp[i] = (dp[i] + curr) % M;
    }
  }

  cout << dp[m] << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  // ll t; cin >> t;
  // while (t--)
  solve();

  return 0;
}
