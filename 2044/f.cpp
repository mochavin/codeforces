#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;

void solve()
{
  ll n, m, q; cin >> n >> m >> q;
  vector<ll> a(n), b(m);
  ll sumA = 0, sumB = 0;
  unordered_map<ll, bool> mpb, mpa;
  loop(i, n) cin >> a[i], sumA += a[i], mpa[a[i]] = true;
  loop(i, m) cin >> b[i], sumB += b[i], mpb[b[i]] = true;

  // all sumB-b
  // loop(i, n) mpa[sumA - a[i]] = true;
  // loop(i, m) mpb[sumB - b[i]] = true;


  while (q--) {
    ll x; cin >> x;
    bool f = false;
    // x = (sumA-a)(sumB-b)    
    for (int i = 1; i * i <= (abs(x)); i++) {
      if (x % i != 0) continue;
      ll del1 = i;
      ll del2 = x / i;

      // Check all combinations of del1 and del2
      f |= (mpa[sumA - del1] && mpb[sumB - del2]);
      f |= (mpa[sumA - del2] && mpb[sumB - del1]);

      // Check negative combinations
      del1 *= -1;
      del2 *= -1;
      f |= (mpa[sumA - del1] && mpb[sumB - del2]);
      f |= (mpa[sumA - del2] && mpb[sumB - del1]);
    }
    cout << (f ? "YES" : "NO") << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  // ll t; cin >> t;
  // while (t--)
  solve();

  return 0;
}
