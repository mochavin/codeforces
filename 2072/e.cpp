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

vector<pair<ll, ll >> f(ll k, ll x, ll y) {
  if (k == 0) return {};
  ll d = 0;
  while (d * (d - 1) / 2 <= k) d++;
  d--;
  auto sisa = f(k - d * (d - 1) / 2, x + d + 1, y + 1);
  vector<pair<ll, ll>> ans;
  for (ll i = x; i < x + d; i++) {
    ans.push_back({ i, y });
  }
  // ans.insert(ans.end(), all(sisa));
  loop(i, sisa.size()) {
    ans.push_back({ sisa[i].first, sisa[i].second });
  }
  return ans;
}

void solve()
{
  ll k; cin >> k;
  if (k == 0) {
    cout << 1 << endl;
    cout << "0 0" << endl; return;
  }
  auto ans = f(k, 0, 0);
  cout << ans.size() << endl;
  for (auto [x, y] : ans) {
    cout << x << " " << y << endl;
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
