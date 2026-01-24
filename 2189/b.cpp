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
  ll n, x; cin >> n >> x;
  ll sum = 0;
  ll mx = LLONG_MIN;
  for (ll i = 0; i < n; i++) {
    ll ina, inb, inc; cin >> ina >> inb >> inc;
    mx = max(mx, ina * inb - inc);
    sum += ina * (inb - 1);
  }

  if (sum >= x) {
    cout << 0 << endl; return;
  }
  if (mx <= 0) {
    cout << -1 << endl; return;
  }
  x -= sum;
  ll ans = (x + mx - 1) / mx;
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
