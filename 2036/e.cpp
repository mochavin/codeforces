#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
#define all(v) v.begin(), v.end()
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;

void solve()
{
  ll n, k, q; cin >> n >> k >> q;
  vector<vector<ll>> v(n);
  loop(i, n) {
    loop(j, k) {
      ll x; cin >> x;
      v[i].push_back(x);
      if (i) {
        v[i][j] |= v[i - 1][j];
      }
    }
  }

  vector<vector<ll>> a(k, vector<ll>(n));
  loop(i, n) {
    loop(j, k) {
      a[j][i] = v[i][j];
      // cout << a[j][i] << " ";
    }
    // cout << endl;
  }

  while (q--) {
    ll m; cin >> m;
    ll ansl = 0, ansr = M, f = 0;
    loop(i, m) {
      ll x, y; char c;
      cin >> x >> c >> y;
      x--, y;
      if (c == '>') {
        ansl = max(ansl, upper_bound(all(a[x]), y) - a[x].begin());
      }
      else {
        ansr = min(ansr, lower_bound(all(a[x]), y) - a[x].begin());
      }
    }
    if (ansl == M) ansl = 0;
    // cout << ansl << " " << ansr << " ";
    if (ansl + 1 > n or ansl > ansr - 1) {
      cout << -1 << endl; continue;
    }
    cout << ansl + 1 << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  // ll t; cin >> t;
  // while (t--)
  solve();

  return 0;
}
