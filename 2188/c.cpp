#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e18;
ll N = 2e5 + 10;

void solve()
{
  ll n; cin >> n;
  vector<ll> v(n);
  ll mx = 0, mn = M;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    mx = max(mx, v[i]);
    mn = min(mn, v[i]);
  }
  vector<ll> s = v, c;
  sort(s.begin(), s.end());
  for (int i = 0; i < n; i++) {
    if (s[i] != v[i]) c.push_back(v[i]);
  }

  n = c.size();
  if (n == 0) {
    cout << -1 << endl; return;
  }

  ll ans = M;
  for (int i = 0; i < n; i++) {
    ans = min(ans, max(mx - c[i], c[i] - mn));
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
