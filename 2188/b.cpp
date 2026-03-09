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
  string s; cin >> s;
  if (n <= 2) {
    cout << 1 << endl; return;
  }
  int ans = 0;
  vector<bool> v(n, false);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      v[i] = true;
      if (i) v[i - 1] = true;
      if (i + 1 < n) v[i + 1] = true;
    }
  }

  for (int i = 0; i < n; i++) {
    if (v[i]) continue;
    if (i < n - 1 and !v[i + 1]) {
      s[i + 1] = '1';
      v[i + 1] = true;
      if (i + 2 < n) v[i + 2] = true;
    }
    else {
      s[i] = '1';
      if (i + 1 < n) v[i + 1] = true;
    }
  }

  // cout << s << " ";

  for (auto x : s) if (x == '1') ans++;
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
