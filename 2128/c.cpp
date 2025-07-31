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
  ll n; cin >> n;
  vector<ll> v(n);
  loop(i, n) {
    cin >> v[i];
  }
  ll mn = v[0], ls = -1;
  int ans = 1;
  loop(i, n) {
    if (v[i] > 2 * mn - 1) ans = 0;
    mn = min(mn, v[i]);
  }

  cout << (ans ? "YES" : "NO") << endl;
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
