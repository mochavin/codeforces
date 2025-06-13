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
  ll n, m, l, r; cin >> n >> m >> l >> r;
  pair<ll, ll> ans;
  if (m > abs(l)) {
    ans = { l, l + m };
  }
  else if (m > abs(r)) {
    ans = { r - m, r };
  }
  else {
    ans = { 0, m };
  }
  cout << ans.first << " " << ans.second << endl;
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
