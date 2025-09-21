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
  vector<pair<ll, ll>> v;
  ll n, k; cin >> n >> k;
  for (int i = 0; i <= 100; i++) {
    ll res = powl(3, i + 1) + i * powl(3, i - 1);
    if (res < 0) break;
    v.push_back({ powl(3, i), res });
  }
  ll m = v.size(), c = 0, coin = 0;
  map<ll, ll> mp;
  for (ll i = m - 1; i >= 0; i--) {
    while (n >= v[i].first) {
      n -= v[i].first;
      c++;
      mp[v[i].first]++;
      coin += v[i].second;
      // cout << mp[v[i].first] << endl;
    }
  }

  // c is the least count deal possible
  if (k < c) {
    cout << -1 << endl;
    return;
  }

  // 9 9 1 1
  for (auto it = mp.rbegin(); it != mp.rend(); it++) {
    // cout << it->first << " " << it->second << endl;
    auto [fs, sc] = *it;
    if (c + 2 * sc <= k) {
      coin -= fs / 3 * sc;
      c += 2 * sc;
      mp[fs / 3] += sc * 3;
    }
    else {
      while (c + 2 <= k) {
        coin -= fs / 3;
        c += 2;
      }
      cout << coin << endl; return;
    }
  }
  cout << coin;
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
