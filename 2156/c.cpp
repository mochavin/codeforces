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
  int n, k; cin >> n >> k;
  vector<ll> v(n);
  vector<int> pre(n + 1);
  loop(i, n) {
    cin >> v[i];
    pre[v[i]]++;
  }
  loop1(i, n) {
    pre[i] += pre[i - 1];
  }
  for (int d = n; d > 0; d--) {
    int c = 0;
    for (int x = 0; x < 4; x++) {
      int l = (d * x + 1), r = min(n, d * (x + 1) - 1);
      if (l <= r) {
        c += pre[r] - pre[l - 1];
      }
    }

    if (c <= k) {
      cout << d << endl; return;
    }
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
