#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 1;

void solve()
{
  ll n, q; cin >> n >> q;
  vector<ll> v(n);
  loop(i, n) cin >> v[i];
  ll sum = accumulate(all(v), 0ll);

  vector<ll> pre(2 * n + 1, 0);
  pre[0] = 0;

  loop1(i, 2 * n) {
    pre[i] = pre[i - 1] + v[(i - 1) % n];
  }

  while (q--) {
    ll l, r; cin >> l >> r;

    l--, r--;
    ll i = l / n, j = r / n;
    l %= n, r %= n;
    cout << pre[n] * (j - i + 1) - (pre[i + l] - pre[i]) - (pre[j + n] - pre[j + r + 1]) << endl;
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
