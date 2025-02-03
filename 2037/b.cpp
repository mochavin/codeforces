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
  vector<ll> v(n);
  map<ll, ll> mp;
  loop(i, n) {
    cin >> v[i];
    mp[v[i]]++;
  }

  ll trg = n - 2;
  loop(i, n) {
    // cek is factor of n-2
    if (trg % v[i] == 0) {
      ll dv = trg / v[i];
      if (dv == v[i]) {
        if (mp[dv] > 1) {
          cout << dv << " " << dv << endl; return;
        }
      }
      else {
        if (mp.find(dv) != mp.end()) {
          cout << v[i] << " " << dv << endl; return;
        }
      }
    }
  }
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
