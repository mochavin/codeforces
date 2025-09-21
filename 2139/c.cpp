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
  ll k, x; cin >> k >> x;
  vector<ll> ans;
  ll sum = (1LL << (k + 1));
  ll s = (sum)-x;
  while (x != s) {
    if (x > s) {
      s *= 2; x = sum - s;
      ans.push_back(2);
    }
    else {
      x *= 2; s = sum - x;
      ans.push_back(1);
    }
  }
  reverse(all(ans));
  cout << ans.size() << endl;
  for (auto x : ans)  cout << x << " ";
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
