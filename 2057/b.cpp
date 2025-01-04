#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;



void solve()
{
  ll n, k; cin >> n >> k;
  vector<ll> v(n);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  priority_queue<pair<ll, ll>> pq2;
  map<ll, ll> mp;
  loop(i, n) {
    cin >> v[i];
    mp[v[i]]++;
  }

  for (auto x : mp) {
    pq.push({ x.second, x.first });
    pq2.push({ x.second, x.first });
  }
  ll ans = pq.size();
  auto high = pq2.top();
  while (k > 0) {
    auto top = pq.top(); pq.pop();
    if (top.second == high.second) break;
    if (k - top.first >= 0) {
      k -= top.first;
      ans--;
    }
    else {
      break;
    }
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
