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
  string a, b, c; cin >> a >> b >> c;
  vector<vector<ll>> v(a.length() + 1, vector<ll>(b.length() + 1, 0));

  loop(i, a.length()) {
    v[i + 1][0] = v[i][0] + (c[i] != a[i]);
  }
  loop(i, b.length()) {
    v[0][i + 1] = v[0][i] + (c[i] != b[i]);
  }

  int n = a.length(), m = b.length();

  loop1(i, n) {
    loop1(j, m) {
      // penentuan untuk i == j == 1
      v[i][j] = v[i - 1][j] + (c[i + j - 1] != a[i - 1]);
      v[i][j] = min(v[i][j], v[i][j - 1] + (c[i + j - 1] != b[j - 1]));
    }
  }

  cout << v[a.length()][b.length()] << endl;
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
