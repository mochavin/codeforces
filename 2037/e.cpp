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

  vector<ll> f(n + 1, 0);
  string s(n, '0');

  ll cek = 0;

  for (ll i = 2; i <= n; i++) {
    f[i] = q(1, i);
    if (f[i] != 0) {
      cek = i;
      if (i == 1) {
        cout << "! IMPOSSIBLE" << endl;
        fflush(stdout);
        return;
      }
      break;
    }
  }

  // 11111111
  // 00000000
  if (!cek) {
    cout << "! IMPOSSIBLE" << endl;
    fflush(stdout);
    return;
  }

  loop(i, cek - f[cek] - 1) {
    s[i] = '1';
  }

  s[cek - 1] = '1';

  for (int i = cek + 1; i <= n; i++) {
    f[i] = q(1, i);
    if (f[i] > f[i - 1]) {
      s[i - 1] = '1';
    }
  }

  cout << "! " << s << endl; fflush(stdout);
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
