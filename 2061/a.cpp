#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;

void solve()
{
  int n; cin >> n;
  ll ans = 0, f = 0;
  loop(i, n) {
    int x; cin >> x;
    if (x % 2) ans++;
    else f = 1;
  }
  if (ans == n) {
    cout << n - 1 << endl; return;
  }
  cout << ans + f << endl;

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
