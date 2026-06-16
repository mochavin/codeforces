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
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(all(v));
  ll s = 0;
  for (auto x : v) s += x;
  for (int i = 0; i < 1e6; i++) {
    if (i == v[0] or i == v[n - 1] or i == s) {
      continue;
    }
    cout << i << endl; return;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  // ll t; cin >> t;
  // while (t--)
  solve();

  return 0;
}
