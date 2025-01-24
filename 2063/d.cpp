#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;


void solve()
{
  ll n, m; cin >> n >> m;
  // if (n < m) swap(m, n);
  vector<ll> a(n), b(m);
  loop(i, n) cin >> a[i];
  loop(i, m) cin >> b[i];
  sort(all(a)), sort(all(b));
  vector<ll> suma(n + 2), sumb(m + 2);
  loop1(i, n) suma[i] = suma[i - 1] + (a[n - i] - a[i - 1]);
  loop1(i, m) sumb[i] = sumb[i - 1] + (b[m - i] - b[i - 1]);
  vector<ll> ans = { 0 };

  // ternary search:
  for (ll x = 1; 2 * x - m <= n - x; x++) {
    ll l = max(0ll, 2 * x - m), r = min(n - x, x);
    if (l > r) break;
    auto f = [&](ll ka) {
      return suma[ka] + sumb[x - ka];
      };
    while (r - l > 3) {
      ll midl = (2 * l + r) / 3, midr = (l + 2 * r) / 3;
      if (f(midl) > f(midr)) r = midr;
      else l = midl;
    }

    ll mx = 0;
    for (ll i = l; i <= r; i++) {
      mx = max(mx, f(i));
    }

    ans.push_back(mx);
  }

  // k max
  cout << ans.size() - 1 << endl;
  loop1(i, ans.size() - 1) cout << ans[i] << " ";
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
