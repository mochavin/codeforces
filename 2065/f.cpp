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
ll N = 2e5 + 1;

void solve()
{
  ll n; cin >> n;
  vector<ll> v(n + 1);
  loop1(i, n) cin >> v[i];

  vector<vector<ll>> adj(n + 1);
  loop(i, n - 1) {
    ll x, y; cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  // ex: 1 2 1 or 1 1
  vector<ll> ans(n + 1, 0);
  loop1(i, n) {
    // is there any sibling with same value
    map<ll, ll> mp;
    for (auto x : adj[i]) {
      if (v[x] == v[i]) {
        ans[v[i]] = 1;
      }
      if (mp[v[x]]) ans[v[x]] = 1;
      mp[v[x]] = 1;
    }
  }
  loop1(i, n) cout << ans[i];
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
