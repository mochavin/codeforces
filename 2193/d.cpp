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
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a.begin(), a.end());
  vector<ll> pre(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + b[i - 1];
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll l = 0, r = n, nn = n;
    ll xx = a[i];
    ll lb = lower_bound(a.begin(), a.end(), xx) - a.begin();
    // cout << lb << " ";
    while (l <= r) {
      ll m = l + (r - l) / 2;
      // cout << m << " ";
      if (pre[m] <= n - lb) {
        nn = m;
        l = m + 1;
      }
      else {
        r = m - 1;
      }
    }
    ans = max(ans, a[i] * nn);
    // cout << endl;
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
