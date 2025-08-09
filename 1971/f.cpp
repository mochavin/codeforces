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
  ll n; cin >> n;
  ll ans = 0;
  for(ll x = 0; x <= n; x++) {
    ll l = 0, r = n, kiri = -1, kanan = -1;
    while(l <= r) {
      ll m = l + (r-l)/2;
      if(x*x + m*m >= n*n) {
        kiri = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    l = 0, r = n;
    while(l <= r) {
      ll m = l + (r-l)/2;
      if(x*x + m*m < (n+1)*(n+1)) {
        kanan = m;
        l = m+1;
      } else {
        r = m-1;
      }
    }
    if(kanan != -1 and kiri != -1) {
      ll curr = (kanan-kiri+1)*4;
      // handle x == y
      // if(kanan == x) {
      //   curr -= 4;
      // }
      // curr -= 4;
      ans += curr;
      // cout << "x: " << x << endl;
      // cout << kanan << " " << kiri << " ";
      // cout << curr << " ";
    }
  }
  // handle y = 0 || x = 0
  cout << ans-4 << endl;
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
