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
  ll n, c; cin >> n >> c;
  vector<ll> a, b;
  loop(i, n) {
    ll in; cin >> in;
    if (in > c) b.push_back(in);
    else a.push_back(in);
  }
  sort(rall(a));
  int ans = b.size(), co = 0;
  loop(i, a.size()) {
    if ((a[i] * (1 << co)) > c) {
      ans++;
    }
    else co++;
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
