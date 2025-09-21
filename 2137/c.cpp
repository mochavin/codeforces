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
  if (a % 2) {
    if (b % 4 and b % 2 == 0) {
      cout << -1 << endl; return;
    }
    if (b % 2) {
      ans = a * b + 1;
    }
    else {
      ll c = 0, co = b;
      while (co % 2 == 0) {
        co /= 2; c++;
      }
      ans = max(a * 2 + b / 2, co * 2 + (a * (ll)powl(2, c - 1)));
      ans = max(ans, a * b / 2 + 2);
    }
  }
  else {
    // a even
    if (b % 2) {
      cout << -1 << endl; return;
    }
    else {
      ll temp = a + b;
      ll c = 0, cc = b;
      while (cc % 2 == 0) {
        cc /= 2; c++;
      }
      ans = max(temp, a * cc + 2);
      ans = max(ans, a * (ll)powl(2, c - 1) + cc * 2);
      ans = max(ans, a * b / 2 + 2);
    }
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
