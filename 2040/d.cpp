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

void solve()
{
  ll n; cin >> n;
  vector<vector<ll>> v(n);
  loop(i, n - 1) {
    ll x, y; cin >> x >> y;
    x--, y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  vector<ll> ans(n);
  ll last = 1;
  ans[0] = last;

  function <void(int, int)> dfs = [&](ll id, ll p) {
    for (ll nei : v[id]) {
      if (nei == p) continue;
      ans[nei] = last + 1;
      while (ans[nei] != ans[id] + 1 and
        (ans[nei] % 2 != ans[id] % 2 or ans[nei] - ans[id] == 2)) {
        ans[nei]++;
      }
      last = ans[nei];
      dfs(nei, id);
    }
    };

  dfs(0, 0);

  for (ll i : ans) cout << i << " ";
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
