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


void solve()
{
  int n; cin >> n;
  pair<ll, ll> p, q;
  cin >> p.first >> p.second >> q.first >> q.second;
  vector<ll> a(n);
  ll mx = 0;
  loop(i, n) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  ll sum = accumulate(all(a), 0ll); sum *= sum;
  ll dis = (p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second);
  if (sum == dis) {
    cout << "YES" << endl; return;
  }
  double sum2 = accumulate(all(a), 0ll), dis2 = sqrt(dis);
  // (sum - mx + dis) >= mx
  if (sum < dis || n == 1 || sum2 - mx + dis2 < mx) {
    cout << "NO" << endl; return;
  }

  cout << "YES" << endl;
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
