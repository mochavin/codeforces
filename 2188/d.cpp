#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
  ll x, y;
  cin >> x >> y;

  ll mn = 1e18, p, q;

  auto f = [&](ll a, ll b) {
    ll d = abs(x - a) + abs(y - b);
    if ((a & b) == 0 and d < mn) {
      mn = d;
      p = a; q = b;
    }
    };

  f(x, y);

  for (int i = 31; i >= 0; i--) {
    if (((x & y) >> i) & 1) {
      f((x >> i << i) + (1 << i), y);
      f(x, (y >> i << i) + (1 << i));
      f(x >> i << i, (y >> i << i) - 1);
      f((x >> i << i) - 1, y >> i << i);
    }
  }

  cout << p << " " << q << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();
}