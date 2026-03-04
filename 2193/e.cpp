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
vector<int> dp(3e5 + 1);

void solve()
{
  int n; cin >> n;
  for (int i = 1; i <= n; i++) dp[i] = M;
  for (int i = 0; i < n; i++) {
    int in; cin >> in; dp[in] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      dp[j] = min(dp[j], dp[i] + dp[j / i]);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << (dp[i] == M ? -1 : dp[i]) << " ";
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
