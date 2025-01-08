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
  ll a, b, c;cin >> a >> b >> c;
  if (a + 1 != c) {
    cout << -1 << endl;
    return;
  }
  if (a == 0) {
    cout << b << endl;
    return;
  }
  // msb of a
  int msb = 0;
  for (int i = 30; i >= 0; i--) {
    if (1 << i & a)  msb = i + 1;
  }

  cout << msb << endl;
  // sisa yang heightnya yg lebih kecil
  ll sisa = 1 << (msb);
  sisa -= a;

  ll rilsisa = sisa - min(b, sisa);
  // b -= min(b, sisa);
  if (b <= sisa) {
    cout << msb << endl;
  }
  else {
    cout << msb + b / (a + 1) << endl;
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
