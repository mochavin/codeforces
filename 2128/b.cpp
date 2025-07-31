#include <bits/stdc++.h>
#include <iostream>
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
  vector<ll> v(n);
  loop(i, n) {
    cin >> v[i];
  }
  int f = 1;
  string ans = "";
  for (int l = 0, r = n - 1; l <= r;) {
    if (f == 1) {
      if (v[l] > v[r]) {
        l++; ans += 'L';
      }
      else {
        r--; ans += 'R';
      }
    }
    else {
      if (v[l] > v[r]) {
        r--; ans += 'R';
      }
      else {
        l++; ans += 'L';
      }
    }
    f *= -1;
  }
  cout << ans << endl;
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
