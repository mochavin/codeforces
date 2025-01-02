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
  ll l2 = (l + (g - 1)) / g, r2 = r / g; // 2, 4
  ll x = l2 * g, y = r2 * g; // 4, 8
  // i: selisih
  for (ll i = r2 - l2; i >= 0; i--) {

    // j: all the pair for sliding window with length i
    for (ll j = l2; j + i <= r2; j++) {
      if (__gcd(j, j + i) == 1) {
        cout << j * g << " " << (j + i) * g << endl;
        return;
      }
    }
  }

  cout << -1 << " " << -1 << endl;
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
