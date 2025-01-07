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
  int n, k, r, c; cin >> n >> k >> r >> c;
  vector<vector<char>> v(n, vector<char>(n, '.'));

  for (int l = -2 * n; l <= 2 * n; l++) {
    for (int i = r - n + l * k, j = c - n; i <= r + n || j <= c + n; i++, j++) {
      if (i > 0 and i <= n and j > 0 and j <= n) {
        v[i - 1][j - 1] = 'X';
      }
    }
    //cout << endl;
  }

  loop(i, n) {
    loop(j, n) cout << v[i][j];
    cout << endl;
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
