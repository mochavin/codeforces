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
  ll n, k; cin >> n >> k;
  vector<ll> v(n);
  loop(i, n) cin >> v[i];
  if (k & 1) {
    // jadiin genap semua
    loop(i, n) {
      if (v[i] & 1) v[i] += k;
    }
  }
  else {
    if (k <= 2) {
      // jadiin gcd == 3
      ll g = k % 3;
      loop(i, n) {
        if (v[i] % 3 == 1) {
          v[i] += (g == 2 ? g : 2 * g);
        }
        else
          if (v[i] % 3 == 2) {
            v[i] += (g == 1 ? g : 2 * g);
          }
      }
    }
    else {
      // jadiin gcd == k-1
      ll g = k - 1;
      loop(i, n) {
        v[i] += (g - v[i] % g) * k;
      }
    }
  }
  for (auto x : v) cout << x << " ";
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
