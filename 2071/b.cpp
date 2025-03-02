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

bool cek(ll n) {
  ll sq = sqrt(n);
  return 1LL * sq * sq == n;
}

void solve()
{
  ll n;
  cin >> n;
  if (cek(n * (n + 1) / 2)) {
    cout << -1 << endl; return;
  }

  vector<ll> v(n);
  loop(i, n) v[i] = i + 1;
  loop(i, n) {
    if (i == 0) continue;
    if (cek(i * (i + 1) / 2)) {
      swap(v[i], v[i - 1]);
    }
  }
  loop(i, n) cout << v[i] << " ";
  cout << endl;

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
