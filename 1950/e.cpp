#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 5;

void solve()
{
  ll n; cin >> n;
  string s; cin >> s;
  map<ll, ll> fct;
  loop1(i, sqrt(n)) {
    if (n % i == 0) fct[n / i] = 1, fct[i] = 1;
  }
  ll ans = n;
  for (auto it = fct.rbegin(); it != fct.rend(); ++it) {
    if (it->first == n) continue;
    string sub = s.substr(0, it->first);
    string cek = "";
    string sub2 = s.substr(it->first, it->first);
    string cek2 = "";

    ll tms = n / it->first;
    loop(i, tms) {
      cek += sub;
    }
    loop(i, tms) {
      cek2 += sub2;
    }
    ll cnt = 0;
    loop(i, n) {
      if (s[i] != cek[i]) cnt++;
      if (cnt > 1) break;
    }
    if (cnt <= 1) ans = min(ans, it->first);
    cnt = 0;
    loop(i, n) {
      if (s[i] != cek2[i]) cnt++;
      if (cnt > 1) break;
    }
    if (cnt <= 1) ans = min(ans, it->first);
    // cout << cek2 << endl;
  }
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
