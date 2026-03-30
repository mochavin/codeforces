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
  ll n, c, k; cin >> n >> c >> k;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  multiset<ll> mt;
  for (auto x : v) mt.insert(x);
  for (auto x : mt) {
    if (x > c) break;
    ll val = min(k, c - x);
    x += val;
    k -= val;
    c += x;
    // cout << x << " ";
  }
  cout << c << endl; return;
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
