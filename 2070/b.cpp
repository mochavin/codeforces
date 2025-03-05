#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (ll i = 0; i < h; i++)
#define loop1(i, h) for (ll i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 10;

void solve()
{
  ll n, x, k; cin >> n >> x >> k;
  string s; cin >> s;
  ll f = 0, c = 0, ans = 0, k2 = k;
  for (int i = 0; i < n and k2 > 0; k2--, i++) {
    if (s[i] == 'R') x++;
    else x--;

    if (f) c++;
    if (x == 0) {
      if (f) {
        cout << (k2 + c + (c - 1)) / c << endl;
        return;
      }
      ans = 1;
      i = -1;
      f = 1;
    }
    // cout << x << " ";
  }
  // cout << endl;
  cout << ans << endl;

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
