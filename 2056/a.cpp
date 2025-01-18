#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;

void solve()
{
  ll n, m; cin >> n >> m;
  ll mnx = M, mny = M, mxx = 0, mxy = 0;
  ll currx = 0, curry = 0;
  loop(i, n) {
    ll x, y; cin >> x >> y;
    if (i == 0) {
      mnx = x;
      mny = y;
    }
    currx += x;
    curry += y;
  }
  mxy = curry + m;
  mxx = currx + m;
  cout << 2 * ((mxy - mny) + (mxx - mnx)) << endl;
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
