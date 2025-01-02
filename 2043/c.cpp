#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 5;



void solve()
{
  ll n; cin >> n;
  vector<ll> v(n), pre(n + 1, 0);
  ll mn = 1e18, mx = -1e18;
  loop(i, n) {
    cin >> v[i];
    pre[i] = v[i] + (i > 0 ? pre[i - 1] : 0);
  }

  set<ll> ans;
  ans.insert(0);
  ll l1 = 0, r1 = 0, l2 = 1e18, r2 = -1e18;
  ll mn1 = 0, mx1 = 0, mn2 = 1e18, mx2 = -1e18;
  loop(i, n) {
    if (v[i] != 1 and v[i] != -1) {
      mx2 = mx1, mn2 = mn1;
      mn1 = pre[i], mx1 = pre[i];
    }
    l1 = min(l1, pre[i] - mx1);
    r1 = max(r1, pre[i] - mn1);
    l2 = min(l2, pre[i] - mx2);
    r2 = max(r2, pre[i] - mn2);
    mx1 = max(mx1, pre[i]), mn1 = min(mn1, pre[i]);
  }

  if (l2 > r1 || r2 < l1) {
    for (ll i = l1; i <= r1; i++) ans.insert(i);
    for (ll i = l2; i <= r2; i++) ans.insert(i);
  }
  else {
    for (ll i = min(l1, l2); i <= max(r1, r2); i++) ans.insert(i);
  }

  cout << ans.size() << endl;
  for (auto x : ans) cout << x << " ";
  cout << endl;

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
