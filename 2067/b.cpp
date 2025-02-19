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
ll N = 2e5 + 10;

void solve()
{
  ll n; cin >> n;
  vector<ll> v(n);
  map<ll, ll> mp1, mp2;
  loop(i, n) {
    cin >> v[i];
    mp1[v[i]]++;
  }
  for (auto [fs, sc] : mp1) {
    mp1[fs] = 0;
    loop(i, sc / 2) {
      mp2[i + fs] += 2;
      mp1[i + fs] += 2;
    }
    if (sc & 1) mp2[sc / 2 + fs]++, mp1[sc / 2 + fs]++;
  }

  for (auto [x, y] : mp1) {
    if (y & 1) {
      cout << "No" << endl; return;
    }
  }
  cout << "Yes" << endl;
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
