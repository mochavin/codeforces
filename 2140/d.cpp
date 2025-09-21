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
  vector<pair<ll, ll>> v(n);
  vector<ll> b(n);
  ll ans = 0, mx = -M;
  loop(i, n) {
    ll x, y; cin >> x >> y;
    v[i] = { x, y };
    ans += y - x;
    ans += y;
    mx = max(y - x, mx);
  }
  loop(i, n) v[i].first += v[i].second;
  sort(all(v));
  ll it = 0;
  vector<ll> vis(n + 1, 0);
  loop(i, (n) / 2) {
    ans -= v[i].first;
    vis[i] = 1;
    it++;
  }
  if (n % 2) {
    ll mx = LLONG_MIN;
    loop(i, n) {
      if (vis[i]) mx = max(mx, v[i].first);
    }
    ans += mx;
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
