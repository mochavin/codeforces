#include <bits/stdc++.h>
#include <iostream>
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
  ll x, k; cin >> x >> k;
  if ((x == 2 and k == 1)) {
    cout << "YES" << endl;
    return;
  }
  else if (x % 2 == 0 or (k > 1 and x != 1) or (x == 1 and k == 1)) {
    cout << "NO" << endl;
    return;
  }

  if (x == 1) {
    loop(i, k - 1) {
      x = x * 10 + 1;
    }
  }

  bool f = 1;
  for (ll i = 3; i * i <= x; i += 2) {
    if (x % i == 0) {
      f = 0; break;
    }
  }

  cout << (f ? "YES" : "NO") << endl;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);

  // for (ll i = 3; i <= 1e9; i += 2) {
  //   for (ll j = i; j <= 1e9; j += i) {
  //     if (isprime[j]) break;
  //     isprime[j] = true;
  //   }
  // }

  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
