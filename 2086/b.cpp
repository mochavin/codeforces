#include <bits/stdc++.h>
#include <iostream>
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
  ll n, k, x; cin >> n >> k >> x;
  vector<ll> a(n);
  loop(i, n) cin >> a[i];
  vector<ll> pos(n);
  pos[n - 1] = a[n - 1];
  for (ll i = n - 2; i >= 0; i--) {
    pos[i] = a[i] + pos[i + 1];
  }
  if (k * pos[0] < x) {
    cout << 0 << endl; return;
  }
  // >= x posfix
  ll t = (x + pos[0] - 1) / pos[0];
  t--;
  x -= t * pos[0];
  for (ll i = n - 1; i >= 0; i--) {
    if (x <= pos[i]) {
      cout << i + 1 + (k - t - 1) * n << endl; return;
    }
  }
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
