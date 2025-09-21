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
  vector<ll> a(n), b(n);
  loop(i, n) cin >> a[i];
  loop(i, n) cin >> b[i];
  vector<pair<ll, ll>> dp(n + 1, { 0, 0 });
  dp[0] = { 1, 1 };
  loop1(i, n - 1) {
    // if (a[i] >= a[i - 1]) {
    //   dp[i].first = dp[i - 1].first;
    // }
    // if (a[i] >= b[i - 1]) {
    //   dp[i].first += dp[i - 1].second;
    // }
    // if (b[i] >= a[i - 1]) {
    //   dp[i].second = dp[i - 1].first;
    // }
    // if (b[i] >= b[i - 1]) {
    //   dp[i].second += dp[i - 1].second;
    // }
    if (a[i] >= a[i - 1] and b[i] >= b[i - 1]) {
      dp[i].first = dp[i - 1].first;
    }
    if (b[i] >= a[i - 1] and a[i] >= b[i - 1]) {
      dp[i].first += dp[i - 1].second;
    }
    if (a[i] >= b[i - 1] and b[i] >= a[i - 1]) {
      dp[i].second = dp[i - 1].first;
    }
    if (a[i] >= a[i - 1] and b[i] >= b[i - 1]) {
      dp[i].second += dp[i - 1].second;
    }
    dp[i].first %= M;
    dp[i].second %= M;
    // cout << dp[i].first << " " << dp[i].second << endl;
  }
  cout << (dp[n - 1].first + dp[n - 1].second) % M << endl;

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
