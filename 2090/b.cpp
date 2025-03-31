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
  ll r, c; cin >> r >> c;
  vector<vector<ll>> mp(r, vector<ll>(c)), cek(r, vector<ll>(c, 0));
  loop(i, r) {
    string s; cin >> s;
    loop(j, c) {
      mp[i][j] = s[j] - '0';
      if (mp[i][j] == 1) {
        if (i == 0) cek[i][j] = 1;
        if (j == 0) cek[i][j] = 2;
        if (i == 0 and j == 0) cek[i][j] = 3;
      }
    }
  }

  loop(i, r) {
    loop(j, c) {
      if (i == 0 or j == 0) continue;
      if (mp[i][j] == 1) {
        int f = 0;
        for (int x = i - 1; x >= 0; x--) {
          if (mp[x][j] == 0) break;
          if (x == 0) f = 1;
        }
        for (int x = j - 1; x >= 0; x--) {
          if (mp[i][x] == 0) break;
          if (x == 0) f = 2;
          // cout << f << " ";
        }
        if (f == 0) {
          cout << "NO" << endl; return;
        }
      }
    }
    // cout << endl;
  }
  // loop(i, r) {
  //   loop(j, c) cout << cek[i][j];
  //   cout << endl;
  // }
  cout << "YES" << endl;
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
