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
  ll n, m; cin >> n >> m;
  vector<ll> v(m);
  ll f = 0, mx = 0;
  loop(i, m) {
    cin >> v[i];
    mx = max(mx, v[i]);
    if (i and !f) {
      if (v[i] == 1 and v[i - 1] != 1) {
        f = 1;
      }
    }
  }
  if (f || (m > 1 and v[0] * v[1] == 1)) {
    cout << 1 << endl; return;
  }

  // 2 3 4 .. ga nyentuh 1
  // 1 2 3 4 .. ga nyentuh 1
  // if(v[0] == 1) {
  ll id = 0;
  // loop(i, m) {
  //   if(i == 0) continue;
  //   if(v[i] == 1) {
  //   }
  // }
  cout << (n - mx + 1) << endl; return;
  // }

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
