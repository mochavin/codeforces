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

bool cek(ll n) {
  while (n) {
    if (n % 10 == 7) return true;
    n /= 10;
  }
  return false;
}

vector<ll> v = { 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999 };
void solve()
{
  ll n;
  cin >> n;
  loop(i, 10) {
    // i operation
    string s = to_string(n - i);
    ll md = 0;
    for (auto c : s) {
      if (c <= '7') {
        md = max(md, (ll)c - '0');
      }
    }
    if (i >= 7 - md) {
      cout << i << '\n';
      return;
    }
  }
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
