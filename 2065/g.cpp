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

vector<vector<ll>> pri(N);
void solve()
{
  ll n; cin >> n;
  vector<ll> v(n);

  map<ll, ll> pricnt;
  loop(i, n) {
    cin >> v[i];
    if (pri[v[i]].size() == 1) {
      pricnt[v[i]]++;
    }
  }



  ll ans = 0, cnt = 0;
  // count ans from prime
  for (auto x : pricnt) {
    cnt += x.second;
  }
  for (auto x : pricnt) {
    ans += (cnt - x.second) * x.second;
    cnt -= x.second;
  }
  // cout << pri[4].size() << " ";
  // cout << pricnt[4] << " ";

  ll temp = 0;
  map<pair<ll, ll>, ll> semicnt;
  unordered_map<ll, ll> mpsq;
  loop(i, n) {
    if (pri[v[i]].size() >= 2) {
      ll fs = pri[v[i]][0], ls = pri[v[i]][1];
      if (fs * ls == v[i] and pri[fs].size() == 1 and pri[ls].size() == 1) {
        // cout << fs << " " << ls << endl;
        semicnt[{fs, ls}]++;
      }
      if (pri[v[i]].size() == 2) {
        mpsq[fs]++;
      }
    }
  }

  // count ans from semi prime
  for (auto x : semicnt) {
    // cout << x.first.first << " " << x.first.second << endl;
    ans += (pricnt[x.first.first] + pricnt[x.first.second]) * x.second;
    ans += x.second * (x.second - 1) / 2;
    ans += x.second;
  }

  // count from square
  for (auto x : mpsq) {
    // cout << x.first << " " << x.second << endl;
    ans += pricnt[x.first] * x.second;
    ans += x.second * (x.second - 1) / 2;
    ans += x.second;
  }


  cout << ans << endl;


}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  for (int i = 2; i < N; i++) {
    for (int j = i; j < N; j += i) {
      if (pri[j].size() >= 3) continue;
      pri[j].push_back(i);
    }
  }
  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
