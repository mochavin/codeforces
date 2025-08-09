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
  string s; cin >> s;
  int n = s.length();
  int f = 0, ans = 1;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != s[i + 1]) {
      if (s[i] == '0' and s[i + 1] == '1') f = 1;
      ans++;
    }
  }
  cout << ans - f << endl;
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
