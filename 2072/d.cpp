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
  ll cnt = 0;
  pair<ll, ll> ans = { 1, 1 };

  ll mx = -M;
  loop(i, n) {
    ll c = 0;
    for (ll j = i + 1; j < n; j++) {
      if (v[j] < v[i]) c++;
      else if (v[j] > v[i]) c--;
      if (c > mx and c >= 0) ans = { i + 1, j + 1 };
      mx = max(mx, c);
    }
  }

  cout << ans.first << " " << ans.second << endl;
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
