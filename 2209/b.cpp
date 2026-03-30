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
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      dp[j][0] += (v[j] > v[i]);
      dp[j][1] += (v[j] < v[i]);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << max(dp[i][0], dp[i][1]) << " ";
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
