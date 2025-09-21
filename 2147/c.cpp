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
  ll n; cin >> n;
  string s; cin >> s;
  // s = '0' + s + '0';
  if (s.find("11011") != s.npos) {
    cout << "NO" << endl; return;
  }
  vector<int> v(n + 5, 0);
  ll c = 0;
  v[0] = 1;
  loop(i, n) {
    if (s[i] == '1') v[i + 1] |= v[i];
    if (s[i] == '0') {
      if ((i and s[i - 1] == '0') or (i == 0)) {
        v[i + 1] |= v[i];
      }
      if (i == n - 1 or s[i + 1] == '0') {
        v[i + 1] |= v[i];
      }
      if (i + 3 <= n and s.substr(i, 3) == "010") {
        v[i + 3] |= v[i];
      }
    }
  }
  // cout << s.substr(n - 4, -1) << " ";
  cout << (v[n] ? "YES" : "NO") << endl;
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
