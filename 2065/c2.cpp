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

void solve()
{
  ll n, m; cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(m));
  vector<pair<ll, ll>> sum(n);
  vector<ll> sum2(n);
  loop(i, n) {
    ll curr = 0;
    loop(j, m) {
      cin >> a[i][j];
      sum2[i] += a[i][j] * (m - j);
    }
    sum[i].second = i;
    sum[i].first = accumulate(all(a[i]), 0ll);
  }

  sort(rall(sum));
  ll ans = 0, curr = 0;
  loop(i, n) {
    // cout << sum[i].first << " ";
    ans += sum2[sum[i].second];
    ans += curr * m;
    curr += sum[i].first;
  }
  cout << ans << endl;


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
