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
ll N = 5e5 + 10;

vector<ll> fac(N);

ll modpow(ll n, ll p) {
  if (p == 0) return 1ll;
  ll res = modpow((n * n) % M, p / 2);
  if (p % 2) res = (res * n) % M;
  return res;
}

ll modinv(ll n) {
  return modpow(n, M - 2);
}

ll C(ll n, ll c) {
  return ((fac[n] * modinv(fac[c]) + M) % M * modinv(fac[n - c]) + M) % M;
}

void solve()
{
  vector<ll> v(26);
  loop(i, 26) cin >> v[i];

  // dp[k] how many set that the sum is k
  ll sum = accumulate(all(v), 0ll);
  vector<ll> dp(sum + 10);
  dp[0] = 1;

  loop(i, 26) {
    if (!v[i]) continue;
    for (ll j = sum; j >= 0; j--) {
      if (v[i] + j >= sum) continue;
      dp[j + v[i]] = (dp[j + v[i]] + dp[j]) % M;
    }
  }

  ll ans = dp[sum / 2] * fac[sum / 2] % M * fac[(sum + 1) / 2] % M;
  loop(i, 26) {
    ans = (ans * modpow(fac[v[i]], M - 2)) % M;
  }
  cout << ans << endl;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  fac[0] = 1;
  loop1(i, N - 1) {
    fac[i] = (fac[i - 1] * i) % M;
  }

  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
