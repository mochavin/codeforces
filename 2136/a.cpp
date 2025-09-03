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
  ll a, b, c, d; cin >> a >> b >> c >> d;
  ll f = 1;
  if (a > b) {
    if (b * 2 + 2 < a) f = 0;
  }
  else {
    if (a * 2 + 2 < b) f = 0;
  }

  c -= a; d -= b;
  a = c; b = d;
  if (a > b) {
    if (b * 2 + 2 < a) f = 0;
  }
  else {
    if (a * 2 + 2 < b) f = 0;
  }

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
