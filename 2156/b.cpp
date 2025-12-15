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
  int n, q; cin >> n >> q;
  string s; cin >> s;
  int f = 0;
  for (auto x : s) {
    if (x == 'B') { f = 1; break; }
  }

  if (!f) {
    while (q--) {
      int a; cin >> a;
      cout << a << endl;
    }
    return;
  }

  while (q--) {
    int a, ans = 0; cin >> a;
    loop(i, n) {
      if (a == 0) break;
      if (s[i] == 'A') a--;
      else a /= 2;
      ans++;
      if (i == n - 1) i = -1;
    }
    cout << ans << endl;
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
