#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (ll i = 0; i < h; i++)
#define loop1(i, h) for (ll i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 10;

void solve()
{
  ll n; cin >> n;
  vector<ll> p(n), d(n);
  vector<vector<ll>> vs(n);
  loop1(i, n - 1) {
    ll x; cin >> x; x--;
    p[i] = x;
    d[i] = d[p[i]] + 1;
    vs[d[i]].push_back(i);
  }
  vector<ll> dp(n), tot(n);
  dp[0] = tot[0] = 1;
  loop1(i, n - 1) {
    for (auto x : vs[i]) {
      dp[x] = (tot[d[x] - 1] + (d[x] == 1 ? 0 : -dp[p[x]]) + M) % M;
      tot[d[x]] = (tot[d[x]] + dp[x] + M) % M;
    }
  }

  ll ans = 0;
  loop(i, n) {
    ans = (ans + dp[i] + M) % M;
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
