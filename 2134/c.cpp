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
  loop(i, n) cin >> v[i];
  if (n == 2) {
    cout << max(v[0] - v[1], 0LL) << endl;
    return;
  }
  ll ans = 0, last = n - 2;
  for (int i = 1; i <= last; i += 2) {
    if (v[i] >= v[i - 1] + v[i + 1]) continue;
    ll need = v[i - 1] + v[i + 1] - v[i];
    ll kurang = min(v[i + 1], need);
    v[i + 1] -= kurang;
    need -= kurang;
    ans += kurang;
    if (need > 0) {
      v[i - 1] -= need;
      ans += need;
    }
  }
  if (n % 2 == 0) {
    ans += max(0LL, v[n - 2] - v[n - 1]);
  }
  cout << ans << endl;
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
