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
  vector<pair<ll, ll>> v(n);
  vector<ll> b(n);
  ll ans = 0, mn = M;
  loop(i, n) {
    ll x, y; cin >> x >> y;
    v[i] = { x, y };
    ans += y - x;
    ans += y;
    mn = min(y, mn);
  }

  sort(all(v), [&](pair<ll, ll> a, pair<ll, ll> b) {
    return a.first + a.second < b.first + b.second;
    });
  // for (auto [x, y] : v) {
  //   cout << x << " " << y << endl;
  // }
  loop(i, n / 2) {
    ans -= (v[i].first + v[i].second);
  }
  // if(n % 2) ans -= (v[(n+1)/2].first + v[(n+1)/2].second);
  if (n & 1) {
    ll mn = M, t = ans;
    for (int i = n / 2; i < n; i++) {
      mn = min(mn, v[i].second);
    }
    t -= mn;
    ll t2 = ans - (v[n / 2].first + v[n / 2].second);
    ll mx = -M;
    for (int i = 0; i < n / 2; i++) {
      mx = max(mx, v[i].first);
    }
    t2 += mx;
    ans = max(t, t2);
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
