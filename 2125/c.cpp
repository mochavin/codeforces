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
  ll ans = 0;
  vector<ll> v = { 2,3,5,7 };
  for (int i = 1; i <= 15; i++) {
    int it = i, c = 0, temp = 1, isMinus = 0;
    while (it) {
      if (it & 1) {
        temp *= v[c];
        isMinus++;
      }
      c++;
      it >>= 1;
    }
    ll lb = (a + temp - 1) / temp, ub = b / temp;
    ll res = ub - lb + 1;
    // cout << "i: " << i << " => " << res << endl;
    if (isMinus % 2) ans += res;
    else ans -= res;
  }
  cout << b - a + 1 - ans << endl;

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
