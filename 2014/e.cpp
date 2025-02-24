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
ll N = 2e5 + 10;
ll n;

map<ll, bool> mp;
vector<vector<pair<ll, ll>>> adj;

vector<vector<ll>> dijstra(ll s) {
  priority_queue<tuple<ll, ll, bool>, vector<tuple<ll, ll, bool>>, greater<tuple<ll, ll, bool>>> pq;
  vector<vector<ll>> dist(2, vector<ll>(n + 1, LLONG_MAX));
  dist[0][s] = 0;
  pq.push({ 0, s, 0 });
  while (!pq.empty()) {
    auto [dis, v, horse] = pq.top();
    pq.pop();
    if (dis > dist[horse][v]) continue;
    bool naik = horse | mp[v];
    for (auto x : adj[v]) {
      ll next = x.first;
      ll w = x.second;
      if (naik) w /= 2;
      if (dist[horse][v] + w < dist[naik][next]) {
        dist[naik][next] = dist[horse][v] + w;
        pq.push({ dist[naik][next], next, naik });
      }
    }
  }
  return dist;
}

void solve()
{
  ll m, h; cin >> n >> m >> h;
  loop(i, h) {
    ll temp; cin >> temp;
    mp[temp] = true;
  }
  adj.clear(); adj.resize(n + 1);
  loop(i, m) {
    ll x, y, d; cin >> x >> y >> d;
    adj[x].push_back({ y, d });
    adj[y].push_back({ x, d });
  }

  ll ans = LLONG_MAX;
  vector<vector<ll>> d1 = dijstra(1), dn = dijstra(n);
  loop1(i, n) {
    ll maxp = max(min(d1[0][i], d1[1][i]), min(dn[0][i], dn[1][i]));
    ans = min(ans, maxp);
  }
  if (ans == LLONG_MAX) cout << -1 << endl;
  else
    cout << ans << endl;
  mp.clear();
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
