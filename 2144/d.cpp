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
  ll n, y; cin >> n >> y;
  vector<ll> v(n), c(N, 0);
  ll mx = LONG_LONG_MIN;
  loop(i, n) {
    cin >> v[i];
    mx = max(mx, v[i]);
    c[v[i]]++;
  }
  vector<ll> pre(mx + 5, 0);
  loop1(i, mx + 1) {
    pre[i] = pre[i - 1] + c[i];
  }
  ll ans = LONG_LONG_MIN;
  for (ll x = 2; x <= mx + 1; x++) {
    ll co = 0;
    for (ll i = 1; (i - 1) * x <= mx; i++) {
      ll cc = pre[min(mx, x * i)] - pre[min(mx, x * (i - 1))];
      co += cc * i + min(c[i], cc) * y;
    }
    ans = max(ans, co);
  }

  cout << ans - n * y << endl;
  // sort(all(v));
  // for (auto x : v) cout << x << " ";
  // cout << endl;
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
