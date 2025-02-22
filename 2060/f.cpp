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
ll N = 2e5 + 5;

ll pw(ll x, ll y) {
  if (!y) return 1;
  ll res = pw(x, y / 2);
  res = res * res % M;
  if (y & 1) res = res * x % M;
  return res;
}

void solve()
{
  ll k, n; cin >> k >> n;
  vector<vector<ll>> dp(18, vector<ll>(k + 1));
  dp[0][1] = 1;
  loop(i, 17) {
    loop1(j, k) {
      for (ll l = j * 2; l <= k; l += j) {
        dp[i + 1][l] = (dp[i + 1][l] + dp[i][j]) % M;
      }
    }
  }

  // for (int i = 0; i < 5; i++) {
  //   for (int j = 0; j <= k; j++) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  loop1(i, k) {
    ll ans = 0, ml = 1;
    loop(j, 18) {
      ml = ml * (n - j + 1) % M * pw(j + 1, M - 2) % M;
      ans = (ans + dp[j][i] * (ml + M - !j)) % M;
    }
    cout << ans << " ";
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
