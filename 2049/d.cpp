#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;

void solve() {
  ll n, m, k; cin >> n >> m >> k;
  vector<vector<ll>> arr(n, vector<ll>(2 * m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      arr[i][j + m] = arr[i][j];
    }
  }

  // the cost is kx + y, where x is operation row shift, and y is the sum of the visited
  // for minimum cost, use dp, the option is either right, down, shift.
  // how to count the shifting?

  // there is f(x) and g(x)
  // f(i, j) is the min cost to move to cell i,j
  // g(i, j, x) is the min cost to move to i,j where row i is shifted left by x


  // base row = 1, col = 0
  vector<vector<ll>> dp(202, vector<ll>(202));
  loop(i, n + 1) {
    loop(j, m + 1) dp[i][j] = 1e18;
  }

  // basecase
  dp[0][0] = 0;
  loop(i, n) {
    loop(j, m) {

      // shift t times, penentuan ans untuk row i+1 and col j, j+1, ..., m
      loop(t, m) {
        ll cost = dp[i][j] + k * t;
        for (int len = 1; j + len <= m; len++) {
          cost += arr[i][j + t + len - 1];
          // when to choose down
          dp[i + 1][j + len - 1] = min(dp[i + 1][j + len - 1], cost);
        }
      }
    }
  }
  cout << dp[n][m - 1] << endl;


  return;
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
