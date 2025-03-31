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

vector<pair<ll, ll>> pr;
map<ll, vector<pair<ll, ll>>> pr2;
void solve()
{
  int n; cin >> n;
  vector<int> v(n);
  loop(i, n) cin >> v[i];
  map<pair<ll, ll>, bool> mp;
  // is reserved?
  map<ll, bool> mp2;
  // !visited and remain
  ll cnt = 0, cnt2 = 0;
  loop(i, n) {
    if (v[i] == 0) {
      auto temp = pr[cnt];
      auto cek = mp[{temp.first / 3, temp.second / 3}];
      while (cek) {
        cnt++;
        temp = pr[cnt];
        cek = mp[{temp.first / 3, temp.second / 3}];
      }
      mp[{temp.first / 3, temp.second / 3}] = true;
      mp2[cnt] = true;

      cout << temp.first << " " << temp.second << endl;
      cnt++;
    }
    else {
      while (mp2[cnt2]) {
        cnt2++;
      }
      auto temp = pr[cnt2];
      mp[{temp.first / 3, temp.second / 3}] = true;
      mp2[cnt2] = true;
      cout << temp.first << " " << temp.second << endl;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);

  ll mx = 0;

  loop1(i, 1000) {
    loop1(j, 1000) {
      if (i % 3 == 0 or j % 3 == 0) continue;
      ll d = i + j + (i % 3 == 2 and j % 3 == 2 ? 2 : 0);
      if (d < 4 * 50005) {
        pr2[d].push_back({ i, j });
        mx++;
      }
      else {
        break;
      }
    }
  }

  loop1(i, mx) {
    if (pr2.find(i) == pr2.end()) continue;
    loop(j, pr2[i].size()) pr.push_back(pr2[i][j]);
  }

  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
