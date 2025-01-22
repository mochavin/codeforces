#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 1;

void solve()
{
  ll n; cin >> n;
  vector<ll> v(n + 1);
  loop1(i, n) cin >> v[i];
  // dp 2d, [index][curr liers], def: solusi banyaknya cara untuk liars cnt segitu, [i][0] -> truth
  vector<vector<ll>> dp(n + 1, vector<ll>(2));
  // find relation to input
  loop1(i, n) {
    if (i == 1) {
      if (v[i] == 0) {
        dp[i][0] = 1;
        dp[i][1] = 1;
      }
      else {
        dp[i][1] = 1;
      }
      continue;
    }

    dp[i][0] = (v[i] == v[i - 1] ? dp[i - 1][0] : 0); // prev truth
    dp[i][0] += (v[i] == v[i - 2] + 1 ? dp[i - 1][1] : 0); // prev lies
    dp[i][1] = dp[i - 1][0];
    dp[i][0] %= M;
    dp[i][1] %= M;
    // cout << i << ": ";
    // cout << dp[i][0] << " " << dp[i][1] << endl;
  }

  ll ans = 0;
  loop(i, 2) {
    ans += dp[n][i];
    ans %= M;
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
