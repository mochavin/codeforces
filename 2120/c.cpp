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
  ll n, m; cin >> n >> m;
  if (m < n || m > n * (n + 1) / 2) {
    cout << -1 << endl; return;
  }

  if (n == m) {
    cout << 1 << endl;
    loop1(i, n - 1) cout << i << " " << i + 1 << endl;
    return;
  }

  vector<ll> ans;
  // base case: root 1
  ll sisa = m - n, curr = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (curr + i <= sisa) {
      curr += i;
      ans.push_back(i + 1);
    }
  }

  ll c = ans.size();
  loop(i, n - c) ans.push_back(1);
  vector<ll> vis(n + 1, 0);
  // cout << "size ans: " << ans.size() << endl;

  cout << ans[0] << endl;
  ll prev = ans[0];
  loop(i, n - 1) {
    cout << ans[i] << " " << ans[i + 1] << endl;
    vis[ans[i]] = 1; vis[ans[i + 1]] = 1;
    if (ans[i + 1] == 1) {
      prev = 1;
      for (int i = n; i >= 1; --i) {
        if (!vis[i]) {
          cout << prev << " " << i << endl;
          prev = i;
        }
      }
      return;
    }
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
