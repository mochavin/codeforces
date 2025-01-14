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
  ll n, k, l; cin >> n >> k >> l;
  vector<ll> v(n);
  loop(i, n) cin >> v[i];

  double L = l, K = k;
  // look at the position crow 
  double waktu = v[0], last = 0, teleport = 0;
  loop1(i, n - 1) {
    double curr = min(L, min(v[i] + waktu, max(last + K, (last + K + v[i] - waktu) / 2.0)));
    teleport += min(K, curr - last);
    waktu += max(0.0, curr - last - K);
    last = curr;
  }
  teleport += min(K, L - last);
  cout << (ll)(2 * (L - teleport + v[0])) << endl;
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
