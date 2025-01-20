#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;

void solve()
{
  ll n, m; cin >> n >> m;
  map<ll, ll> mp;
  loop(i, n) {
    loop(j, m) {
      ll x; cin >> x;
      mp[x] = i + 1;
    }
  }

  vector<ll> ans;
  loop(i, n) {
    ans.push_back(mp[i]);
  }

  loop(i, m * n) {
    if (mp[i] != ans[i % n]) {
      cout << -1 << endl; return;
    }
  }
  loop(i, n) cout << ans[i] << " ";

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
