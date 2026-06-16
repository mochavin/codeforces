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
  ll a, b, c, m; cin >> a >> b >> c >> m;
  vector<ll> ans(3, 0ll);
  ll AB = lcm(a, b), AC = lcm(a, c), BC = lcm(b, c);
  ll kpk = lcm(a, BC);
  ans[0] = 6 * (m / a) - 3 * (m / AB) - 3 * (m / AC) + 2 * (m / kpk);
  ans[1] = 6 * (m / b) - 3 * (m / AB) - 3 * (m / BC) + 2 * (m / kpk);
  ans[2] = 6 * (m / c) - 3 * (m / BC) - 3 * (m / AC) + 2 * (m / kpk);
  for (auto x : ans) cout << x << " ";
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
