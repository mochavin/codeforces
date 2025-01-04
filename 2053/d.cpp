#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 5;

ll ipow(ll a) {
  ll res = 1, b = M - 2;
  a %= M;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return res;
}


void solve()
{
  ll n, q; cin >> n >> q;
  vector<ll> a(n), b(n);
  loop(i, n) cin >> a[i];
  loop(i, n) cin >> b[i];
  vector<ll> x = a, y = b;
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  ll ans = 1;
  loop(i, n) ans = ans * min(x[i], y[i]) % M;
  cout << ans << " ";
  if (q == 0) {
    cout << endl; return;
  }

  loop(i, q) {
    ll op, id; cin >> op >> id;
    id--;
    if (op == 1) {
      auto p = upper_bound(x.begin(), x.end(), a[id]) - x.begin() - 1;
      a[id]++;
      if (x[p] < y[p]) ans = ans * ipow(x[p]) % M * (x[p] + 1) % M;
      x[p]++;
    }
    else {
      auto p = upper_bound(y.begin(), y.end(), b[id]) - y.begin() - 1;
      b[id]++;
      if (x[p] > y[p]) ans = ans * ipow(y[p]) % M * (y[p] + 1) % M;
      y[p]++;
    }
    cout << ans << " ";
    if (i == q - 1) cout << endl;
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
