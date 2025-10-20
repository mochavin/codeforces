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
  ll n, q; cin >> n >> q;
  vector<int> v(n), pre(n, 0), d(n, 0), ds(n, 0);
  loop(i, n) {
    cin >> v[i];

    if (i) {
      pre[i] = v[i] + pre[i - 1];
      d[i] = (v[i] != v[i - 1]);
      ds[i] = d[i] + ds[i - 1];
      // cout << ds[i] << " ";
    }
    else {
      pre[i] = v[i];
    }
  }
  // for (auto x : ds) cout << x << " ";
  // cout << endl;
  while (q--) {
    ll l, r; cin >> l >> r;
    r--, l--;
    ll t = r - l + 1;
    if ((t % 3 != 0) ||
      (l == 0 and pre[r] % 3 != 0) ||
      (l != 0 and ((pre[r] - pre[l - 1]) % 3 != 0))
      ) {
      cout << -1 << endl; continue;
    }
    ll f = (ds[r] - ds[l]) == r - l;
    // cout << ds[r] - (l ? ds[l - 1] : 0) << " ";
    cout << t / 3 + f << endl;
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
