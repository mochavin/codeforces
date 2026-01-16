#include <bits/stdc++.h>
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
  ll a, b; cin >> a >> b;
  vector<ll> ans;
  // 100
  // 101
  ll c = 0;
  while (a) {
    if ((a & 1ll) != (b & 1ll)) {
      ans.push_back(1ll << c);
    }
    a /= 2; b /= 2;
    c++;
  }
  if (b != 0) {
    cout << -1 << endl; return;
  }
  cout << ans.size();
  if (ans.size()) cout << endl;
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
