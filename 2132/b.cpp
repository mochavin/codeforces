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
  ll n; cin >> n;
  // n = 11x_1 = 101x_2 = 1001x_2
  vector<ll> v;
  ll it = 1;
  for (ll i = 1; i <= 18; i++) {
    v.push_back(powl(10, it++) + 1);
  }
  vector<ll> ans;
  for (auto x : v) {
    if (x > n) break;
    if (n % x == 0) ans.push_back(x);
  }
  cout << ans.size() << endl;
  if (ans.size() == 0) return;
  sort(ans.rbegin(), ans.rend());
  for (auto x : ans) cout << n / x << " ";
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
