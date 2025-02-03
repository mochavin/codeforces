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
  ll n, m, l; cin >> n >> m >> l;
  vector<pair<ll, ll>> h(n), p(m);
  loop(i, n) {
    cin >> h[i].first >> h[i].second;
  }
  loop(i, m) {
    cin >> p[i].first >> p[i].second;
  }

  priority_queue<ll> pq;

  ll ans = 0, it = 0, pow = 1, acc = 0;
  for (int i = 0; i < n; i++) {
    ll need = h[i].second - h[i].first + 2;
    ll j;
    for (j = it; j < m and p[j].first < h[i].first; j++) {
      pq.push(p[j].second);
      acc += p[j].second;
    }
    it = j;
    if (pow + acc < need) {
      cout << -1 << endl; return;
    }
    while (!pq.empty() and pow < need) {
      ll top = pq.top(); pq.pop();
      // need -= top;
      acc -= top;
      pow += top;
      // cout << need << " ";
      ans++;
    }
    if (pow < need) {
      cout << -1 << endl; return;
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
