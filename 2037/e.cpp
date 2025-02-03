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

int count01Subsequences(const string& s) {
  int count_0 = 0;
  int result = 0;

  for (char c : s) {
    if (c == '0') {
      count_0++;
    }
    else if (c == '1') {
      result += count_0;
    }
  }
  cout << s << " ";
  return result;
}

long long q(int l, int r) {
  cout << "? " << l << " " << r << endl;
  fflush(stdout);
  long long ans;
  cin >> ans;
  return ans;
}

void solve()
{
  ll n;
  cin >> n;

  vector<ll> f(n + 1);
  for (ll i = 1; i <= n; i++) {
    f[i] = q(i, n);
  }

  string s(n, '?');
  ll ones = 0;

  for (ll i = 1; i < n; i++) {
    if (f[i] == f[i + 1]) {
      s[i - 1] = '1';
      ones++;
    }
    else {
      s[i - 1] = '0';
    }
  }

  if (f[n] == 0) {
    if (ones == 0) s[n - 1] = '1';
    else s[n - 1] = '0';
  }
  else {
    cout << "! IMPOSSIBLE" << endl;
    return;
  }

  for (char c : s) {
    if (c == '?') {
      cout << "! IMPOSSIBLE" << endl;
      return;
    }
  }

  cout << "! " << s << endl;


}

int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(0);

  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
