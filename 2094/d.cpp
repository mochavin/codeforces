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
  string s1, s2; cin >> s1 >> s2;
  ll n1 = s1.length(), n2 = s2.length();
  vector<pair<char, ll>> v1;
  ll ls = 0;
  loop(i, n1) {
    if (i == n1 - 1 || s1[i] != s1[i + 1]) {
      v1.push_back({ s1[i], i - ls + 1 });
      ls = i + 1;
    }
  }
  ls = n2 - 1;
  for (ll i = n2 - 1; i >= 0; i--) {
    if (i == 0 || s2[i] != s2[i - 1]) {
      if (v1.empty()) {
        cout << "NO" << endl;
        return;
      }
      pair<char, ll> pr = v1.back();
      ll cnt = ls - i + 1;
      // cout << cnt << " ";
      if (cnt < pr.second || s2[i] != pr.first || cnt > 2 * pr.second) {
        cout << "NO" << endl;
        return;
      }
      v1.pop_back();
      ls = i - 1;
    }
  }
  cout << (v1.empty() ? "YES" : "NO") << endl;
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
