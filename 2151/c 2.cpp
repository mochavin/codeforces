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
  ll n; cin >> n;
  vector<ll> v(2 * n), pre(2 * n, 0);
  loop(i, 2 * n) {
    cin >> v[i];
    if (i) {
      if (i % 2) pre[i] = pre[i - 1] + v[i];
      else pre[i] = pre[i - 1] - v[i];
    }
    else pre[i] = -v[i];
  }
  ll ans = pre[2 * n - 1];
  cout << ans << " ";
  loop1(i, n - 1) {
    ll m = pre[2 * n - i - 1] - pre[i - 1];
    if (i % 2) {
      m *= -1;
      ans += 2 * m;
      cout << ans << " ";
    }
    else {
      ans += 2 * m;
      cout << ans << " ";
    }
  }

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
