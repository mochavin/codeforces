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
  int n; cin >> n;
  vector<double> c(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    cin >> p[i];
    p[i] = 1 - p[i] * 0.01;
  }

  double ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    // c1 + 0.8 c2 + 0.4 c4
    // dp4
    // dp3 = dp4
    // dp2 = c3 * 0.5 + c2
    // dp1 = dp2 * 0.8 + c1 = c3 * 0.4 + c2 * 0.8 + c1
    ans = max(ans, p[i] * ans + c[i]);
  }

  cout << fixed << setprecision(10) << ans << endl;
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
