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
  int n; cin >> n;
  vector<ll> v(n);
  loop(i, n) cin >> v[i];
  vector<ll> dp(n + 1, 0);
  dp[0] = 1;
  ll c = 1;
  loop1(i, n - 1) {
    dp[i] = dp[i - 1];
    if (v[i] > v[i - 1]) {
      c += 1;
    }
    else {
      c += i + 1;
    }
    dp[i] += c;
  }
  cout << dp[n - 1] << endl;

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
