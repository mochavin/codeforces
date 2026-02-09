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
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) a[i] = max(a[i], b[i]);
  for (int i = n - 2; i >= 0; i--) {
    a[i] = max(a[i], a[i + 1]);
  }
  vector<ll> pre(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i - 1];
  }
  while (q--) {
    int l, r; cin >> l >> r;
    cout << pre[r] - pre[l - 1] << " ";
  }
  cout << endl;
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
