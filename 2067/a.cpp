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
  int x, y; cin >> x >> y;
  if (x + 1 == y or ((x + 1 - y) % 9 == 0 and x > y)) {
    cout << "Yes" << endl;
    return;
  }
  cout << "No" << endl; return;
  // 19 20 -> 10 2
  // 99 100 -> 18 1
  // 119 120 -> 11 3
  // 199 200 -> 19 2
  // 2999 3000 -> 29 3
  // 1299 1300 -> 21 4
  // 999999 10000000 -> kelipatan 9 dan 1
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
