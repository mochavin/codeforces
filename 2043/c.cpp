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

set<ll> ans;
vector<ll> pre(N, 0);
unordered_map<ll, unordered_map<ll, bool>> mp;

void devide(ll l, ll r) {
  // cout << l << " " << r << " " << pre[r] - (l > 0 ? pre[l - 1] : 0) << endl;
  if (l > r || mp[l][r]) return;
  mp[l][r] = true;
  ans.insert(pre[r] - (l > 0 ? pre[l - 1] : 0));
  devide(l, r - 1);
  devide(l + 1, r);
  return;
}


void solve()
{
  ll n; cin >> n;
  vector<ll> v(n);
  loop(i, n) cin >> v[i];
  pre[0] = v[0];
  loop(i, n) {
    if (i > 0) pre[i] = pre[i - 1] + v[i];
  }
  ans.insert(0);
  devide(0, n - 1);
  cout << ans.size() << endl;
  for (ll x : ans) cout << x << " ";
  cout << endl;
  ans.clear();
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
