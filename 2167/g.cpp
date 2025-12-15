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
  ll a[n], c[n], s = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    s += c[i];
  }

  ll dp[n];
  memset(dp, 0, sizeof(dp));
  ll t = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = c[i];
    for (int j = 0; j < i; j++) {
      if (a[i] >= a[j]) {
        dp[i] = max(dp[i], dp[j] + c[i]);
      }
    }
    t = max(t, dp[i]);
  }

  cout << s - t << endl;
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
