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
  vector<vector<ll>> val(n + 2, vector<ll>(2)), op(n + 2, vector<ll>(2, 0)), f(n + 2, vector<ll>(2, 0));
  loop1(i, n) {
    loop(j, 2) {
      char in;
      cin >> in >> val[i][j];
      if (in == '+') op[i][j] = 1;
    }
  }
  f[n][0] = 1, f[n][1] = 1;
  for (ll i = n; i >= 1; i--) {
    loop(j, 2) {
      if (op[i][j] == 1) f[i - 1][j] = f[i][j];
      else f[i - 1][j] = f[i][j] + (val[i][j] - 1) * max(f[i][j], f[i][j ^ 1]);
    }
  }

  ll ans = f[0][0] + f[0][1];
  loop1(i, n) {
    loop(j, 2) {
      if (op[i][j] == 1) {
        ans += val[i][j] * max(f[i][0], f[i][1]);
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
