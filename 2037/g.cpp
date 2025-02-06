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
ll M = 998244353;
ll N = 2e5 + 1;

void solve()
{
  ll n; cin >> n;
  vector<ll> v(n), ans(n);
  loop(i, n) cin >> v[i];

  ans[0] = 1;

  // mobius function
  // tampung semua divisor
  // dp untuk prev index divisor
  ll mx = *max_element(all(v));

  vector<vector<ll>> dv(mx + 2);

  loop1(i, mx) {
    for (ll j = i; j <= mx; j += i) {
      dv[j].push_back(i);
    }
    // cout << i << ": " << dv[i].size() << endl;
  }

  // mob function
  // μ(n) = 1 - sum_{d|n, d < n} μ(d)
  vector<ll> mob(mx + 1, 1);
  mob[1] = 0;
  loop1(i, mx) {
    for (ll j = 2 * i; j <= mx; j += i) {
      mob[j] -= mob[i];
    }
  }

  // for (int i = 1; i <= mx; i++) {
  //   cout << "μ(" << i << ") = " << mob[i] << "\n";
  // }

  // tampung ans untuk div 
  vector<ll> tmp(mx + 1);

  loop(i, n) {
    for (auto x : dv[v[i]]) {
      // PIE
      ans[i] = (ans[i] + ((tmp[x] * mob[x]) % M + M) % M) % M;
    }
    if (i == 0) {
      ans[i] = 1;
    }
    for (auto x : dv[v[i]]) {
      tmp[x] = ((tmp[x] + ans[i]) % M + M) % M;
    }
  }

  cout << ans[n - 1] % M << endl;
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
