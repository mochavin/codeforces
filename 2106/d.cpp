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
  ll n, m; cin >> n >> m;
  vector<ll> a(n), b(m);
  loop(i, n) cin >> a[i];
  loop(i, m) cin >> b[i];
  vector<ll> pr(m), su(m);
  for (int i = 0, j = 0; i < m; i++) {
    while (j < n and a[j] < b[i]) j++;
    pr[i] = j; j++;
  }
  for (int i = m - 1, j = n - 1; i >= 0; i--) {
    while (j >= 0 and a[j] < b[i]) j--;
    su[i] = j; j--;
  }
  if (pr[m - 1] < n) {
    cout << 0 << endl; return;
  }

  ll ans = 2 * M;
  for (int i = 0; i < m; i++) {
    ll kanan = i == m - 1 ? n : su[i + 1];
    ll kiri = i == 0 ? -1 : pr[i - 1];
    if (kanan > kiri) {
      ans = min(b[i], ans);
    }
  }
  cout << (ans == 2 * M ? -1 : ans) << endl; return;

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
