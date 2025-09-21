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
  ll n, m; cin >> n >> m;
  vector<ll> v(n);
  ll mx = 0;
  loop(i, n) {
    cin >> v[i];
    mx = max(mx, v[i]);
  }
  if (n == 1) {
    cout << mx * m << endl; return;
  }
  if (m == 1) {
    cout << mx << endl; return;
  }
  sort(all(v));
  ll ans = 0;
  if (m >= n) {
    ll c = m - n + 1;
    ans += v[0] * c;
    // cout << ans << " ";
    c++;
    loop1(i, n - 1) {
      ans += v[i] * c;
      c++;
      // cout << ans << " ";
    }
  }
  else {
    ll it = n - m;
    ll c = 1;
    for (int i = it; i < n; i++) {
      ans += v[i] * c; c++;
    }
  }
  // for (auto x : v) cout << x << " ";
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
