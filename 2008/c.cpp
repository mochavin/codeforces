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
ll N = 2e5 + 5;

void solve()
{
  ll x, y; cin >> x >> y;
  ll l = 0, r = 1e9 + 1;
  ll target = y - x + 1;
  while (l <= r) {
    ll mid = (l + r) / 2;
    ll val = mid * (mid + 1) / 2;

    if (val >= target) {
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << l << endl;
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
