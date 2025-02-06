#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 1;

void solve()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = 0;
  if (a > b) swap(a, b);
  if (c > d) swap(c, d);

  // turn 1
  if (a >= c) {
    if (b > d) ans++;
    else if (b == d and a > c) ans++;
  }

  if (a >= d) {
    if (b > c) ans++;
    else if (b == c and a > d)  ans++;
  }

  if (b >= c) {
    if (a > d) ans++;
    else if (a == d and b > c) ans++;
  }

  if (b >= d) {
    if (a > c) ans++;
    else if (a == c and b > d) ans++;
  }

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
