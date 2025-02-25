#include <bits/stdc++.h>
#include <iostream>
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
  string s; cin >> s;
  vector<ll> v(n, 0);
  v[0] = (s[0] == '-');
  loop(i, n) {
    if (!i) continue;
    v[i] = v[i - 1] + (s[i] == '-');
  }
  ll ans = (v[n - 1] + 1) / 2 * (v[n - 1] / 2) * (n - v[n - 1]);
  // loop(i, n) {
  //   if (s[i] == '_') {
  //     ans += v[i] * (v[n - 1] - v[i]);
  //   }
  // }
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
