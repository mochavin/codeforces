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
  loop(i, n) cin >> a[i];
  loop(i, n) cin >> b[i];
  map<ll, ll> mp;
  loop(i, n - 1) {
    if ((a[i] ^ a[i + 1]) == b[i]) {
      // cout << ((a[i] ^ a[i + 1])) << " ";
      a[i] ^= a[i + 1];
      mp[i] = 1;
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    if ((a[i] ^ a[i + 1]) == b[i] and mp.find(i) == mp.end()) {
      mp[i] = 1;
      a[i] ^= a[i + 1];
    }
  }
  loop(i, n) {
    if (a[i] != b[i]) {
      // cout << i << ": ";
      // cout << a[i] << " " << b[i] << " ";
      cout << "NO" << endl; return;
    }
  }
  cout << "YES" << endl;
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
