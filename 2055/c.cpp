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

void solve()
{
  int n, m; cin >> n >> m;
  string s; cin >> s;
  vector<vector<ll>> v(n, vector<ll>(m));
  vector<ll> sumrow(n, 0), sumcol(m, 0), cntrow(n, 0), cntcol(m, 0);
  loop(i, n) {
    loop(j, m) {
      cin >> v[i][j];
      sumrow[i] += v[i][j];
      sumcol[j] += v[i][j];
    }
  }

  map<pair<ll, ll>, int> mp;

  int x = 0, y = 0;
  mp[{0, 0}] = 1;
  cntrow[0]++;
  cntcol[0]++;
  loop(i, s.length()) {
    if (s[i] == 'D') y++;
    else x++;
    mp[{x, y}] = 1;
    cntrow[y]++;
    cntcol[x]++;
  }

  // sum row and col (x) must 0
  v[0][0] = (s[0] == 'D' ? -sumrow[0] : -sumcol[0]);
  sumrow[0] = sumrow[0] + v[0][0];
  sumcol[0] = sumcol[0] + v[0][0];
  cntcol[0]--;
  cntrow[0]--;
  x = 0, y = 0;
  loop(i, s.length()) {
    if (s[i] == 'D') {
      y++;
    }
    else {
      x++;
    }
    if (cntrow[y] == 1) {
      v[y][x] = -sumrow[y];
    }
    if (cntcol[x] == 1) {
      v[y][x] = -sumcol[x];
    }
    sumrow[y] += v[y][x];
    sumcol[x] += v[y][x];
    cntrow[y]--;
    cntcol[x]--;
  }

  loop(i, n) {
    loop(j, m) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
  return;


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
