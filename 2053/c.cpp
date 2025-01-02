#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 5;

ll ans = 0, k, cnt = 0;

pair<ll, ll> devide(ll l, ll r, ll d) {
  ll len = r - l + 1, m = (l + r) / 2, sum = 0;
  pair<ll, ll> res = { 0, 0 };
  if (len < k) return res;
  if (len % 2 == 1) {
    auto left = devide(l, m - 1, d + 1);
    res.first += m + 2 * left.first + left.second * m;
    res.second = 1 + left.second; // count this level + children
  }
  else {
    auto left = devide(l, m, d + 1);
    res.first += 2 * left.first + left.second * m;
    res.second = left.second; // only count children
  }

  return res;
}

void solve()
{
  ll n; cin >> n >> k;

  cout << devide(1, n, 1).first << endl;
  cnt = 0;

  ans = 0;
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
