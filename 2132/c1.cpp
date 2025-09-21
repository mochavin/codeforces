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
  vector<pair<ll, ll>> v;
  ll n; cin >> n;
  for (int i = 0; i <= 100; i++) {
    ll res = powl(3, i + 1) + i * powl(3, i - 1);
    if (res < 0) break;
    v.push_back({ powl(3, i), res });
    // cout << powl(3, i) << " ";
    // cout << res << endl;
  }
  ll m = v.size();
  ll ans = 0;
  for (ll i = m - 1; i >= 0; i--) {
    while (n >= v[i].first) {
      n -= v[i].first;
      ans += v[i].second;
    }
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
