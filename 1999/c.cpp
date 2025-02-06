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
  int n, s, m; cin >> n >> s >> m;
  vector<pair<ll, ll>> v(n);
  loop(i, n) cin >> v[i].first >> v[i].second;
  sort(all(v));
  if (s <= v[0].first or s <= m - v.back().second) {
    cout << "YES" << endl; return;
  }

  for (int i = 0; i < n - 1; i++) {
    if (v[i + 1].first - v[i].second >= s) {
      cout << "YES" << endl; return;
    }
  }

  cout << "NO" << endl;
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
