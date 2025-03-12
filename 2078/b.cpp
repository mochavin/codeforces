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
  ll n, k; cin >> n >> k;
  // set semua ke n atau n-1
  // klo k genap, semua ke n-1
  vector<ll> v(n);
  if (k % 2 == 0) {
    loop(i, n) v[i] = n - 1;
    v[n - 2] = n;
  }
  else {
    loop(i, n) v[i] = n;
    v[n - 1] = n - 1;
  }
  loop(i, n) cout << v[i] << " ";
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
