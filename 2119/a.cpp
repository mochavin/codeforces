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
  int a, b, x, y; cin >> a >> b >> x >> y;
  if (a == b) {
    cout << 0 << endl; return;
  }
  if (b > a) {
    ll ans = 0;
    while (a < b) {
      if (a % 2 == 0) ans += min(x, y);
      else ans += x;
      a++;
    }
    cout << ans << endl;
  }
  else {
    if (b == a - 1 and a & 1) {
      cout << y << endl;
    }
    else {
      cout << -1 << endl;
    }
  }
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
