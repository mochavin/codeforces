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
  vector<vector<ll>> adj(n + 1);
  vector<ll> deg(n + 1, 0);
  loop(i, n - 1) {
    ll x, y; cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    deg[x]++, deg[y]++;
  }

  ll ans = 0;
  loop1(i, n) {
    ll mx = 0;
    for (auto x : adj[i]) {
      mx = max(mx, deg[x]);
    }
    // karena tree ga bakal child i dan x terhubung
    // deg i + deg x, ada penambahan mx-2 pada ketika x diambil
    ans = max(ans, deg[i] + mx - 2);
  }


  multiset<ll> ms;
  loop1(i, n) ms.insert(deg[i]);

  loop1(i, n) {
    ms.erase(ms.find(deg[i]));
    for (auto x : adj[i]) {
      ms.erase(ms.find(deg[x]));
    }

    if (ms.size()) {
      ans = max(ans, deg[i] + *(ms.rbegin()) - 1);
    }

    ms.insert(deg[i]);
    for (auto x : adj[i]) ms.insert(deg[x]);
  }

  cout << ans << endl;
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
