#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 5;

void solve()
{
  ll l, r, g; cin >> l >> r >> g;
  // find the smallest x st. g|x
  ll x = (l + g - 1) / g * g;
  ll a = x;
  if (x < l) {
    a += g;
  }

  if (a > r) {
    cout << "-1 -1" << endl;
    return;
  }
  // find greatest y st. g|y and y less than r
  ll y = r / g * g;
  while (__gcd(a, y) != g && y - g >= l) {
    y -= g;
  }
  if (__gcd(a, y) != g) cout << "-1 -1";
  else cout << a << " " << y;
  cout << endl;
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
