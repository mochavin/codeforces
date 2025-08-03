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
  ll n, s; cin >> n >> s;
  ll ans = 0;
  loop(i, n) {
    pair<ll, ll> d, p;
    cin >> d.first >> d.second >> p.first >> p.second;
    if (d.first * d.second == -1) {
      if (p.first + p.second == s) ans++;
    }
    else {
      if (p.first == p.second) ans++;
    }
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
