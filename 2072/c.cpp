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
  ll n, x; cin >> n >> x;
  ll f = 0;
  vector<ll> ans;
  loop(i, min(n, x)) {
    if ((i | x) != x) f = 1;
    else ans.push_back(i);
  }

  if (n > ans.size()) {
    ll cek = 0;
    loop(i, ans.size()) {
      cek |= ans[i];
    }

    for (auto x : ans) {
      cout << x << " ";
    }
    loop(i, n - ans.size()) {
      cout << x << " ";
    }
  }
  else {
    ll cek = 0;
    loop(i, ans.size() - 1) {
      cout << ans[i] << " ";
      cek |= ans[i];
    }
    if ((cek | (ans.size() - 1)) == x) cout << ans.back();
    else cout << x;
  }

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
