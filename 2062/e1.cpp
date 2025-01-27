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
ll M = 998244353;
ll N = 2e5 + 1;

void solve()
{
  // find any node that it is the second largest in 
  // the tree(without counting subtree that not through root (1))
  ll n; cin >> n;
  vector<pair<ll, ll>> w(n);
  vector<vector<ll>> v(n);
  vector<ll> depth(n), par(n);
  loop(i, n) {
    cin >> w[i].first;
    w[i].second = i;
  }
  loop(i, n - 1) {
    ll x, y; cin >> x >> y;
    x--, y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  vector<pair<ll, ll>> cl = w;

  queue<pair<int, int>> q;
  q.push({ 0, 0 });
  vector<bool> vis(n);
  vis[0] = true;
  while (!q.empty()) {
    auto [node, d] = q.front();
    q.pop();
    depth[node] = d;
    for (auto child : v[node]) {
      if (!vis[child]) {
        vis[child] = true;
        q.push({ child, d + 1 });
        par[child] = node;
      }
    }
  }

  sort(rall(w));
  // if all same
  if (w[0].first == w[n - 1].first) {
    cout << 0 << endl; return;
  }

  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    if (w[i].first == w[0].first) {
      cnt++;
      continue;
    }
    // cek all the child of this node
    ll cntEqualTow0 = 0;
    queue<int> bfs;
    bfs.push(w[i].second);
    vector<bool> visi(n, false);
    visi[w[i].second] = true;
    while (!bfs.empty()) {
      int curr = bfs.front();
      bfs.pop();
      for (auto child : v[curr]) {
        if (!visi[child] && child != par[curr]) {
          // cout << child << " ";
          visi[child] = true;
          bfs.push(child);
          if (w[curr].first >= cl[child].first) {
            cntEqualTow0++;
          }
        }
      }
    }
    cout << cntEqualTow0 << " ";
    if (cntEqualTow0 <= cnt - 1) {
      cout << w[i].second + 1 << endl;
      return;
    }
  }

  cout << 0 << endl;

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
