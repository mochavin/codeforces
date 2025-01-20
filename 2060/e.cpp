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
ll N = 2e5 + 5;

vector<ll> parent, sizes;

ll find_set(ll v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (sizes[a] < sizes[b])
      swap(a, b);
    parent[b] = a;
    sizes[a] += sizes[b];
  }
}

void solve()
{
  ll n, m1, m2; cin >> n >> m1 >> m2;

  // Initialize DSU
  parent.resize(n + 1);
  sizes.resize(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  loop(i, m1) {
    // edge graph 1
    ll x, y; cin >> x >> y;
  }

  loop(i, m2) {
    ll x, y; cin >> x >> y;
  }
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
