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
  int x, y; cin >> x >> y;
  if (x > y) {
    cout << "NO" << endl; return;
  }
  if ((x + y) % 2) y--;
  else x--;
  // cout << x << " " << y << " ";
  if (x < 0 or y < 0) {
    cout << "NO" << endl; return;
  }
  cout << "YES" << endl;
  int c = 3;
  for (int i = 2; i < 2 + y; i++) {
    cout << "1 " << i << endl;
    c = i + 1;
  }
  for (int i = 2; i < 2 + x; i++) {
    cout << i << " " << c++ << endl;
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
