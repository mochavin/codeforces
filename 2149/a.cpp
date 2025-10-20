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
  ll gnv = LONG_LONG_MIN, lpv = LONG_LONG_MAX;
  ll c = 0, c0 = 0;
  loop(i, n) {
    cin >> v[i];
    if (v[i] < 0) c++, gnv = max(v[i], gnv);
    else if (v[i] == 0) c0++;
    else lpv = min(lpv, v[i]);
  }
  if (c % 2 == 0) {
    cout << c0 << endl; return;
  }
  else {
    cout << c0 + min(lpv, -gnv) + 1 << endl;
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
