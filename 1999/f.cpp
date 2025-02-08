#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 10;

ll modpow(ll a, ll b) {
  ll r = 1;
  while (b) {
    if (b & 1) r = (r * a) % M;
    b /= 2;
    a = (a * a) % M;
  }
  return r;
}

vector<ll> fact(N);

ll c(ll n, ll k) {
  if (n < k) return 0ll;
  return (fact[n] * modpow((fact[n - k] * fact[k]) % M, M - 2)) % M;
}

void solve()
{
  ll n, k; cin >> n >> k;
  vector<ll> v(n);
  loop(i, n) cin >> v[i];

  ll ones = 0;
  loop(i, n) ones += v[i];

  ll ans = 0;
  // iterasi berdasarkan kemunculan ones, bukan posisi tengahnya
  for (ll cnt = k / 2 + 1; cnt <= min(ones, k); cnt++) {
    ans += (c(ones, cnt) * c(n - ones, k - cnt)) % M;
    ans %= M;
  }
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  fact[0] = 1;
  fact[1] = 1;
  loop1(i, N) fact[i] = (fact[i - 1] * i) % M;
  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
