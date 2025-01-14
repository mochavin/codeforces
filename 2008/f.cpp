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

ll modpow(ll base, ll exp) {
  ll result = 1;
  base %= M;
  while (exp > 0) {
    if (exp & 1)
      result = (result * base) % M;
    base = (base * base) % M;
    exp >>= 1;
  }
  return result;
}

void solve()
{
  int n; cin >> n;
  vector<ll> v(n);
  ll sum = 0;
  loop(i, n) {
    cin >> v[i];
    sum = (sum + v[i]) % M;  // Prevent overflow in sum
  }

  ll pembilang = 0;
  ll currentSum = sum;
  loop(i, n) {
    currentSum = (currentSum - v[i] + M) % M;  // Handle negative numbers
    pembilang = (pembilang + (v[i] * currentSum) % M) % M;
  }

  ll penyebut = (((ll)n * (n - 1)) / 2) % M;
  ll invPenyebut = modpow(penyebut, M - 2);
  ll ans = (pembilang * invPenyebut) % M;
  if (ans < 0) ans = (ans + M) % M;  // Ensure positive result

  cout << ans << endl;
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
