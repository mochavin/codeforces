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
  ll n, m, k; cin >> n >> m >> k;
  vector<ll> a(n), b(m);
  loop(i, n) cin >> a[i];
  loop(i, m) cin >> b[i];

  // find all possible operation with b
  vector<ll> f(1 << m);
  f[0] = (1 << 30) - 1;
  loop1(i, ((1 << m) - 1)) {
    int u = __builtin_ctz(i);
    f[i] = f[i ^ (1 << u)] & b[u];
  }

  vector<ll> h;
  h.reserve(n * m);
  loop(i, n) {
    vector<ll> g(m + 1);
    loop(j, (1 << m)) {
      ll c = __builtin_popcount(j);
      g[c] = max(g[c], a[i] - (a[i] & f[j]));
    }
    loop1(j, m) {
      // untuk k nya
      h.push_back(g[j] - g[j - 1]);
    }
  }

  sort(rall(h));

  ll ans = accumulate(all(a), 0ll);
  loop(i, h.size()) {
    if (i >= k) break;
    ans -= h[i];
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
