#include <bits/stdc++.h>
#include <bit>
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
  ll l, r; cin >> l >> r;
  ll n = r - l + 1;
  vector<ll> v(n);
  iota(all(v), l);

  ll L = 0, R = n;
  for (ll i = 60; i >= 0; i--) {
    ll x = L;
    while (x < R and (~v[x] >> i & 1)) {
      x++;
    }

    if (x - L < R - x) {
      ll m = 2 * x - L;
      reverse(v.begin() + L, v.begin() + m);
      L = m;
    }
    else {
      ll m = 2 * x - R;
      reverse(v.begin() + m, v.begin() + R);
      R = m;
    }
  }

  ll ans = 0;
  loop(i, n) ans += (v[i] | (l + i));
  cout << ans << endl;
  for (auto x : v) cout << x << " ";
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
