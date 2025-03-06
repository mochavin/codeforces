#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (ll i = 0; i < h; i++)
#define loop1(i, h) for (ll i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 10;

void solve()
{
  ll n, k; cin >> n >> k;
  string s; cin >> s;
  vector<ll> a(n);
  loop(i, n) cin >> a[i];
  ll l = 0, r = 1e10, ans = r + 1;
  while (l <= r) {
    ll mid = (l + r) / 2;
    ll t = 0, w = 0;
    loop(i, n) {
      if (a[i] > mid) {
        if (s[i] == 'B') {
          if (w == 0) w = 1, t++;
        }
        else w = 0;
      }
    }
    if (t <= k) ans = mid, r = mid - 1;
    else l = mid + 1;
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
