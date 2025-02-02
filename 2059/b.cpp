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
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  loop(i, n) cin >> a[i];
  // apakah mungkin untuk b pertama != 1
  // cek != 2
  ll maxspread = n - k + 1;
  // jawaban antara 1 atau 2 kecuali n == k;
  if (n == k) {
    ll ans = 1;
    for (int i = 1; i < n; i += 2) {
      if (a[i] == ans) ans++;
      else break;
    }
    cout << ans << endl;
    return;
  }

  // if (a[2] != 1 or a[1] != 1) {
  //   cout << 1 << endl; return;
  // }

  ll cnt = 0;
  loop1(i, n - 1) {
    if (a[i] == 1) cnt++;
    else break;
  }

  if (n - cnt >= k) {
    cout << 1 << endl; return;
  }

  cout << 2 << endl;

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
