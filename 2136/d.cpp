#include <bits/stdc++.h>
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 10;

void solve()
{
  int n; cin >> n;
  vector<pair<ll, ll>> v(n);
  ll mn1 = 1e12, mn2 = -1e12;
  loop(i, n) {
    cin >> v[i].first >> v[i].second;
    mn1 = min(mn1, v[i].first - v[i].second);
    mn2 = max(mn2, v[i].first + v[i].second);
  }
  ll maxx = 1e9;
  ll res;
  cout << "? L " << maxx << endl;
  cin >> res;
  cout << "? L " << maxx << endl;
  cin >> res;
  cout << "? U " << maxx << endl;
  cin >> res;
  cout << "? U " << maxx << endl;
  cin >> res;
  // res = xi - (X-2v) + Y+2v-yi
  // res = xi-yi - X + Y + 4v
  ll XminY = mn1 - res + 4 * maxx;

  cout << "? R " << maxx << endl;
  cin >> res;
  cout << "? R " << maxx << endl;
  cin >> res;
  cout << "? R " << maxx << endl;
  cin >> res;
  cout << "? R " << maxx << endl;
  cin >> res;
  // res = Y+2v-yi + X+2v-xi
  // X+Y = res-4v+xi+yi
  ll XplusY = res - 4 * maxx + mn2;
  ll x = (XminY + XplusY) / 2;
  ll y = XplusY - x;
  cout << "! " << x << " " << y << endl;
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
