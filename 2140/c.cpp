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
  vector<ll> v(n);
  ll ans = 0;
  loop(i, n) {
    cin >> v[i];
    if (i % 2) ans -= v[i];
    else ans += v[i];
  }
  if (n == 1) {
    cout << v[0] << endl; return;
  }
  ll t = ans;
  // tukar paritas sama
  // 0 4 -> 4, 0 3 -> 4
  ans = max(ans, t + (n % 2 ? n - 1 : n - 2));

  // tukar beda paritas
  // 2*(ai-aj) + |i-j| 
  ll mxOdd = LLONG_MIN * 10, mnEven = LLONG_MAX / 10;
  // a0-a1+a2-a3+a4
  // i = 1: a0 - a1 --> a1-a0+1-0
  // i = 2: a2,a1 --> 2a1-2a2+2-1
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      ans = max(ans, t + 2 * (v[i]) + i - mnEven);
      mxOdd = max(mxOdd, 2 * v[i] - i);
    }
    else {
      ans = max(ans, t + mxOdd - (2 * v[i]) + i);
      mnEven = min(mnEven, 2 * v[i] + i);
      // cout << ans << " ";
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
