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
  int n; cin >> n;
  vector<int> v(n);
  int mn = n + 4, mx = 0, c = 0;
  ll sum = 0;
  loop(i, n) {
    cin >> v[i];
    if (v[i] != i + 1) { mn = min(mn, i + 1); mx = max(mx, i + 1); }
    if (v[i] == 0) c++;
  }
  if (c == 1) {
    mn = n + 4, mx = 0;
    sum = accumulate(all(v), 0ll);
    ll hilang = (n * (n + 1) / 2) - sum;
    loop(i, n) {
      if (v[i] != i + 1 and v[i] != 0) { mn = min(mn, i + 1); mx = max(mx, i + 1); }
      if (v[i] == 0 and hilang != i + 1) {
        mn = min(mn, i + 1); mx = max(mx, i + 1);
      }
    }
    if (mn == n + 4) {
      cout << 0 << endl; return;
    }
  }
  if (c == 0) {
    if (mn == n + 4) cout << 0 << endl;
    else cout << mx - mn + 1 << endl;
    return;
  }
  cout << mx - mn + 1 << endl;

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
