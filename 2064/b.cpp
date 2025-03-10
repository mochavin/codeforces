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
  ll n; cin >> n;
  vector<ll> v(n);
  map<ll, ll> mp;
  loop(i, n) {
    cin >> v[i];
    mp[v[i]]++;
  }

  ll l = -1, r = -1, cnt = 0, ans = 0;
  loop(i, n) {
    if (mp[v[i]] > 1) {
      cnt = 0;
      continue;
    }
    cnt++;
    if (cnt > ans) {
      r = i + 1; l = r - cnt + 1;
      ans = cnt;
    }
  }
  if (l == -1) {
    cout << 0 << endl; return;
  }
  cout << l << " " << r << endl;
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
