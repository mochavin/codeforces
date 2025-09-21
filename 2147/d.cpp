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
  vector<ll> v(n);
  map<ll, ll> mp;
  loop(i, n) {
    cin >> v[i];
    mp[v[i]]++;
  }
  vector<pair<ll, ll>> c;
  for (auto [fs, se] : mp) {
    c.push_back({ se,fs });
  }
  sort(rall(c));
  ll ans1 = 0, ans2 = 0, f = 1;
  for (auto [fs, se] : c) {
    // fs: banyaknya, se = valuenya
    if (f == 1) {
      ans1 += (se + 1) / 2 * fs;
      ans2 += (se) / 2 * fs;
      if (se % 2) f = -f;
    }
    else {
      ans2 += (se + 1) / 2 * fs;
      ans1 += (se) / 2 * fs;
      if (se % 2) f = -f;
    }
  }
  cout << ans1 << " " << ans2 << endl;

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
