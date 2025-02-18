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
  ll n, k; cin >> n >> k;
  vector<ll> v(n);
  ll sum = 0, mx = 0;
  loop(i, n) {
    cin >> v[i];
    sum += v[i]; mx = max(mx, v[i]);
  }
  for (int i = n; i >= 1; i--) {
    if (i * mx <= sum + k and (sum + k) / i * i >= sum) {
      cout << i << endl; return;
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
