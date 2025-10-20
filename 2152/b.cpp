#include <bits/stdc++.h>
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
  ll n; cin >> n;
  ll a, b, c, d; cin >> a >> b >> c >> d;
  // korban a, b
  if (b == d) {
    if (a < c) {
      cout << c << endl; return;
    }
    else {
      cout << (n - c) << endl; return;
    }
  }
  else if (a == c) {
    if (b < d) {
      cout << d << endl; return;
    }
    else {
      cout << (n - d) << endl; return;
    }
  }
  // ada 4 kasus
  if (a < c) {
    if (b < d) { cout << max(c, d) << endl; return; }
    else { cout << max(c, n - d) << endl; return; }
  }
  else {
    if (b < d) { cout << max(d, n - c) << endl; return; }
    else { cout << max(n - c, n - d) << endl; return; }
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
