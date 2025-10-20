#include <bits/stdc++.h>
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
  ll n; cin >> n;
  vector<ll> v(2 * n);
  loop(i, 2 * n) {
    cin >> v[i];
  }
  ll sum = 0, sum2 = 0;
  vector<ll> presum(n, 0), presum2(n, 0);
  loop(i, n) {
    if (i) presum[i] += presum[i - 1], presum2[i] += presum2[i - 1];
    presum[i] += v[2 * i + 1] - v[2 * i];
    if (i) presum2[i] += v[2 * i] - v[2 * i - 1];
  }
  cout << presum[n - 1] << " ";

  ll tt = 0, ans = 0;
  loop(i, n - 1) {
    tt += v[2 * n - i - 1] - v[i];
    ans = tt;
    if (i % 2 == 0) {
      // klo dijumlah indexnya itu n
      ans += presum2[n - (i / 2 + 1)] - presum2[i / 2];
    }
    else {
      // klo dijumlah indexnya jadi n-1
      ans += presum[n - 1 - ((i) / 2 + 1)] - presum[(i) / 2];
    }
    cout << ans << " ";
  }
  cout << endl;
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
