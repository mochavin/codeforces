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
  ll n; cin >> n;
  vector<string> g(n);
  loop(i, n) cin >> g[i];
  vector<ll> ans(n);
  loop(i, n) ans[i] = i;
  sort(all(ans), [&](ll x, ll y) {
    if (g[x][y] == '1')  return x < y;
    else return x > y;
    });

  loop(i, n) cout << ans[i] + 1 << " ";
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
