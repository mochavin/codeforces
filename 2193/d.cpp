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
  vector<ll> a(n), b(n + 1, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];

  int lv = 0, sum = 0;
  ll ans = 0;
  sort(a.rbegin(), a.rend());

  for (int i = 1; i <= n; i++) {
    while (lv < n and sum + b[lv + 1] <= i) {
      sum += b[lv + 1];
      lv++;
    }

    ans = max(ans, lv * a[i - 1]); // lv * x
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
