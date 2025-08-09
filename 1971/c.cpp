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
  int a, b, c, d; cin >> a >> b >> c >> d;
  if (a > b) swap(a, b);
  if (c > d) swap(c, d);

  int f = 0;
  for (int i = a + 1; i != a; i++) {
    i = (i + 12) % 12;
    if (i == (c % 12) || i == (d % 12)) {
      f++; break;
    }
    if (i == (b % 12)) {
      cout << "NO" << endl; return;
    }
  }
  for (int i = (a - 1 + 12) % 12; i != a; i--) {
    i = (i + 12) % 12;
    if (i == (c % 12) || i == (d % 12)) {
      f++; break;
    }
    if (i == (b % 12)) {
      cout << "NO" << endl; return;
    }
  }
  cout << (f == 2 ? "YES" : "NO") << endl;
  return;
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
