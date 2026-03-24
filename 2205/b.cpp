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
  int n; cin >> n;
  map<int, int> mp;
  int t = n;
  for (int i = 2; i * i <= n; i++) {
    while (t % i == 0) {
      mp[i]++;
      t /= i;
    }
  }

  if (t != 1) mp[t]++;

  int ans = 1;
  for (auto [val, count] : mp) {
    ans *= val;
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
