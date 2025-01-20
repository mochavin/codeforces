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

struct DSU {
  vector<int> parent, rank;
  ll sz;

  DSU(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    sz = n;
    iota(parent.begin(), parent.end(), 0); // Inisialisasi parent[i] = i
  }

  int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]); // Path compression
  }

  bool unite(int u, int v) {
    int rootU = find(u), rootV = find(v);
    if (rootU == rootV) return false; // Sudah dalam satu set
    sz--;
    if (rank[rootU] > rank[rootV]) {
      parent[rootV] = rootU;
    }
    else if (rank[rootU] < rank[rootV]) {
      parent[rootU] = rootV;
    }
    else {
      parent[rootV] = rootU;
      rank[rootU]++;
    }
    return true;
  }
};

void solve()
{
  ll n, m1, m2; cin >> n >> m1 >> m2;
  DSU dsu1(n), dsu2(n);
  vector<pair<ll, ll>> edge1;
  loop(i, m1) {
    ll x, y; cin >> x >> y;
    x--, y--;
    edge1.push_back({ x, y });
  }
  loop(i, m2) {
    ll x, y; cin >> x >> y;
    x--, y--;
    dsu2.unite(x, y);
  }

  ll ans = 0;
  for (auto [x, y] : edge1) {
    if (dsu2.find(x) != dsu2.find(y)) {
      ans++;
    }
    else {
      dsu1.unite(x, y);
    }
  }

  cout << ans + (dsu1.sz - dsu2.sz) << endl;
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
