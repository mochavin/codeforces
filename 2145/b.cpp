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
  ll n, k; cin >> n >> k;
  string s; cin >> s;
  if (n == k) {
    loop(i, n) cout << '-';
    cout << endl; return;
  }
  vector<char> ans(n, '+');
  ll it = 0, c = 0, cc = 0;
  ll l = 0, r = n - 1;
  for (;it < k; it++) {
    if (s[it] == '0') {
      ans[l++] = '-'; cc++;
    }
    else if (s[it] == '1') {
      ans[r--] = '-'; cc++;
    }
    else {
      c++;
    }
  }
  ll tt = c;
  ll f = 0;
  for (;l <= r and tt > 0;tt--) {
    if (l == r and k == n) {
      loop(i, n) ans[i] = '-';
      break;
    }
    ans[l++] = '?';
    ans[r--] = '?';
  }
  for (auto x : ans) cout << x;
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
