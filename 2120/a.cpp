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
  vector<pair<ll, ll>> v(3);
  loop(i, 3) cin >> v[i].first >> v[i].second;
  int f = 0;
  // l1 + l2 + l3 = b1 = b2 = b3
  if (v[0].first + v[1].first + v[2].first == v[0].second and v[0].second == v[1].second and v[0].second == v[2].second) f = 1;
  // b1 + v2 + b3 = l1 = l2 = l3
  if (v[0].second + v[1].second + v[2].second == v[0].first and v[0].first == v[1].first and v[0].first == v[2].first) f = 1;
  // l1 = l2 + l3 = b1 + b2 = b1 + b3 --> b2 = b3
  if (v[0].first == v[1].first + v[2].first and v[0].first == v[0].second + v[1].second and v[0].first == v[0].second + v[2].second) f = 1;
  // b1 = b2 + b3 = l1 + l2 = l1 + l3 --> l2 = l3
  if (v[0].second == v[1].second + v[2].second and v[0].second == v[0].first + v[1].first and v[0].second == v[0].first + v[2].first) f = 1;
  cout << (f ? "YES" : "NO") << endl;
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
