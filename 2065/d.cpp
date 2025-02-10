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

  sort(all(b));

  a[0] = min(a[0], b[0] - a[0]);
  for (int i = 1; i < n; i++) {
    // minimum a[i] st. a[i] >= a[i-1]
    // b[j] - a[i] >= a[i-1] or a[i] >= a[i-1]
    // b[j] >= a[i-1] + a[i], find smallest j
    if (b[m - 1] - a[i] < a[i - 1] and a[i] < a[i - 1]) {
      // cout << a[0] << " ";
      cout << "NO" << endl;return;
    }

    // ada b yang membuat b - a[i] >= a[i-1]
    ll l = 0, r = m - 1;
    while (l < r) {
      ll mid = (r + l) / 2;
      if (b[mid] - a[i] >= a[i - 1]) r = mid;
      else l = mid + 1;
    }

    // b[l] - a[i] valid;
    ll temp = b[l] - a[i];
    if (temp >= a[i - 1] or a[i] >= a[i - 1]) {
      if (temp > a[i]) {
        if (a[i] < a[i - 1]) {
          a[i] = temp;
          continue;
        }
        a[i] = min(a[i], temp);
        continue;
      }
      if (a[i] > temp) {
        if (temp < a[i - 1]) {
          continue;
        }
        a[i] = min(a[i], temp);
      }
    }
    else {
      cout << "NO" << endl;return;
    }

  }

  loop(i, n - 1) {
    if (a[i + 1] < a[i]) {
      cout << "NO" << endl;return;
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
