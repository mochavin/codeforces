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
  vector<ll> a(n), b(n);
  loop(i, n) {
    cin >> a[i];
  }
  ll po = 0, ne = 0;
  loop(i, n) {
    cin >> b[i];
    if (a[i] - b[i] >= 0) po += a[i] - b[i];
    else ne += b[i] - a[i];
  }
  cout << po + 1 << endl;

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
