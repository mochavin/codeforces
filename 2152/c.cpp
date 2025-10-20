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
  vector<int> v(n), pre(n, 0), p1(n, 0), p2(n, 0);
  loop(i, n) {
    cin >> v[i];
    if (i) pre[i] = pre[i - 1] + v[i];
    else pre[i] = v[i];
    if (i) {
      if (i & 1) {
        p1[i] = v[i] + ((i & 1 and i >= 2) ? p1[i - 2] : p1[i - 1]);
        p2[i] = p2[i - 1];
      }
      else {
        p2[i] = v[i] + ((i % 2 == 0 and i >= 2) ? p2[i - 2] : p2[i - 1]);
        p1[i] = p1[i - 1];
      }
    }
    else {
      p2[i] = v[i];
      p1[i] = 0;
    }
  }
  // loop(i, n) {
  //   cout << p1[i] << " ";
  // }
  // cout << endl;
  // loop(i, n) {
  //   cout << p2[i] << " ";
  // }
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

    if (t % 2) {
      cout << t / 3 << endl; continue;
    }

    ll f = 0, c = pre[r] - (l ? pre[l - 1] : 0);
    // if (r & 1) {
    ll val = p1[r] - (l ? p1[l - 1] : 0);
    if (val == c and c == t / 2) f = 1;
    // }
    // else {
    val = p2[r] - (l ? p2[l - 1] : 0);
    if (val == c and c == t / 2) f = 1;
    // }
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
