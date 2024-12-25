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

void solve() {
  ll n, k; cin >> n >> k;
  vector<ll> a(n), b(n);
  loop(i, n) cin >> a[i];
  loop(i, n) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<ll> v(2 * n);
  loop(i, n) v[2 * i] = a[i], v[2 * i + 1] = b[i];
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  auto bad = [&](ll p) {
    ll ida = (ll)(lower_bound(a.begin(), a.end(), p) - a.begin());
    ll idb = (ll)(lower_bound(b.begin(), b.end(), p) - b.begin());
    return ida - idb;
    };

  // buyer cnt
  auto cnt = [&](ll p) {
    ll idb = (ll)(lower_bound(b.begin(), b.end(), p) - b.begin());
    return n - idb;
    };

  ll ans = 0;
  loop(i, 2 * n) {
    ll neg = bad(v[i]);
    if (neg <= k) {
      ll buycnt = cnt(v[i]);
      ans = max(ans, buycnt * v[i]);
    }
  }

  cout << ans << endl;

  return;

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
