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
ll M = 1e18 + 7;
ll N = 2e5 + 1;

void solve()
{
  ll n, k; cin >> n >> k;
  vector<ll> ans(n), vis(n, 0);
  ll curr = 1;
  // place curr in index k-1, 2k-1, 3k-1
  for (ll i = k - 1; i < n; i += k) {
    ans[i] = curr;
    curr++;
    vis[i] = 1;
  }
  loop(i, n) {
    ans[i] = (!vis[i] ? curr++ : ans[i]);
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
