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
ll N = 2e5 + 5;

void solve()
{
  ll n, k; cin >> n >> k;
  vector<ll> v(n);
  loop(i, n) {
    cin >> v[i];
  }

  ll fpb = v[0];
  loop(i, n) {
    fpb = gcd(v[i], fpb);
    if (fpb == 1) break;
  }
  if (n == 1) {
    if (k > v[0]) cout << k << endl;
    else cout << k - 1 << endl;
    return;
  }
  if (fpb == 1) {
    cout << n + k - 1 << endl; return;
  }

  if (k < fpb) {
    cout << k << endl; return;
  }

  // 0 4 8 12 16
  ll frag = (k - 1) / (fpb - 1);
  // cout << k + frag << endl;
  ll ans = k + min(frag, n - 1);
  cout << ans << endl;
  // 4 -> 5, 5 -> 6, 6 -> 7
  // 7 -> 9, 8 -> 10, 9 -> 11
  // 10 -> 13, 11 -> 14, 12 -> 15

  // 0 2 4 6
  // 1 -> 1, 2 -> 3, 3 -> 5, 4 -> 7

  // setiap fpb-1, jawabnya nambah 1 thd k, dan penambahan ini berlaku jika masih ada di range fpb * (n-1)


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
