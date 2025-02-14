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
  vector<vector<ll>> v(n);
  loop(i, n) {
    loop(j, n) {
      ll in; cin >> in;
      v[i].push_back(in);
    }
  }

  ll ans = 1;
  vector<ll> suf(n, 0);
  loop(i, n) {
    for (int j = n - 1; j >= 0; j--) {
      if (v[i][j] != 1) break;
      suf[i]++;
    }
  }

  sort(all(suf));
  loop(i, n) {
    if (suf[i] == 0) continue;
    if (ans <= suf[i]) ans++;
    else if (ans < suf[i]) break;
  }

  cout << min(n, ans) << endl;

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
