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
  vector<ll> h(n + 1, 0);
  loop1(i, n) cin >> h[i];
  vector<ll> dp(n + 1);

  dp[0] = 0;
  dp[1] = h[1];
  for (ll i = 2; i <= n; i++) {
    dp[i] = min(dp[i - 1] + h[i] - 1,
      dp[i - 2] + h[i - 1] + h[i] - min(i - 1, h[i]));
  }
  // loop1(i, n) cout << dp[i] << " ";
  // cout << endl;
  cout << dp[n] << endl;
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
