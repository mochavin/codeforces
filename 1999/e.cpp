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
  ll l, r; cin >> l >> r;
  ll ans = 0;
  vector<ll> pangkat3;
  for (int i = 1; i <= 1e6; i *= 3) {
    pangkat3.push_back(i);
  }
  ll curr = upper_bound(all(pangkat3), l) - pangkat3.begin();
  ans += 2 * curr;
  for (int i = l + 1; i <= r; i++) {
    ans += (min(r + 1, pangkat3[curr]) - i) * (curr);
    // cout << i << " " << (min(r, pangkat3[curr]) - i) * (curr);
    i = pangkat3[curr] - 1;
    curr++;
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
