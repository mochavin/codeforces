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
  vector<ll> v(n), pre(n, 0);
  loop(i, n) {
    cin >> v[i];
  }
  loop(i, n) {
    if (i) pre[i] = max(pre[i - 1], v[i]);
    else pre[i] = v[i];
    if (i % 2) v[i] = max(pre[i], v[i]);
  }
  ll ans = max(0ll, v[0] - v[1] + 1);
  loop(i, n) {
    if (i == 0) continue;
    if (i % 2 == 0) {
      if (v[i] >= pre[i - 1]) {
        ans += v[i] - pre[i - 1] + 1;
      }
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
