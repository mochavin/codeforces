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
ll N = 1e6 + 10;

vector<ll> c(N);

void precalc() {
  c[0] = c[1] = 0;
  for (int i = 2; i < N; ++i) {
    c[i] = c[i - 1];
    int x = i;
    while (x % 2 == 0) {
      x /= 2, c[i]++;
    }
  }
}

void solve()
{
  ll n, k; cin >> n >> k;
  if (n == 1) {
    cout << k << endl; return;
  }

  --n;
  for (int i = 0; i <= n; ++i) {
    cout << k * (c[n] == c[i] + c[n - i]) << " \n"[i == n];
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);

  precalc();

  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
