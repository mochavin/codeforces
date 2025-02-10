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
  int n, m; cin >> n >> m;
  vector<ll> a(n), b(m);
  loop(i, n) cin >> a[i];
  loop(i, m) cin >> b[i];

  // set a[0]
  a[0] = min(a[0], b[0] - a[0]);

  for (int i = 1; i < n; i++) {
    ll temp = b[0] - a[i];
    if (a[i] >= a[i - 1] or temp >= a[i - 1]) {
      int f = 0;
      if (a[i] >= a[i - 1]) {
        f++;
      }
      if (temp >= a[i - 1]) {
        f++;
      }
      if (f == 1) {
        a[i] = max(a[i], temp);
      }
      else if (f == 2) {
        a[i] = min(a[i], temp);
      }

    }
    else {
      cout << "NO" << endl;
      return;
    }
  }

  loop(i, n - 1) {
    if (a[i + 1] < a[i]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl; return;
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
