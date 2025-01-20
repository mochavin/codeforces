#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;

bool cek(ll a, ll b, ll c) {
  return a + b == c;
}

void solve()
{
  vector<int> v(4);
  loop(i, 4) cin >> v[i];
  // case 1, ans = 1+2
  ll ans = 1;
  ll v1 = v[0] + v[1];
  ll v2 = v[2] - v[1];
  ll v3 = v[3] - v[2];
  if (v1 == v2) {
    if (v1 == v3) ans = 3;
    else ans = 2;
  }
  else if (v1 == v3) {
    if (v1 == v2) ans = 3;
    else ans = 2;
  }
  else if (v2 == v3) {
    if (v1 == v2) ans = 3;
    else ans = 2;
  }
  else {
    ans = 1;
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
