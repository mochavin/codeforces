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
  ll n, l, r, k; cin >> n >> l >> r >> k;

  // pasti bener
  if (n & 1) {
    cout << l << endl; return;
  }

  ll msb = 0, cek = l;
  while (cek) {
    msb++;
    cek >>= 1;
  }

  ll kanan = (1LL << msb);
  if (n <= 2 || kanan > r) { cout << -1 << endl; return; }

  if (k > n - 2) {
    cout << kanan << endl; return;
  }
  else {
    cout << l << endl; return;
  }

  // cout << l << " " << (1 << (msb)) << endl;
  if (k > n - 2) {
    if (r < kanan) cout << -1 << endl;
    else
      cout << (1 << msb) << endl;
  }
  else {
    cout << l << endl;
  }


  // loop1(i, 1000) {
  //   loop1(j, 1000) {
  //     if ((i & j) == (i ^ j)) cout << i << " " << j << endl;
  //   }
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
