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
  int n, q; cin >> n >> q;
  vector<int> v(n);
  loop(i, n) cin >> v[i];

  // use sparse table to precompute
  // https://cp-algorithms.com/data_structures/sparse-table.html
  vector<vector<int>> st(27, vector<int>(n + 1));
  loop(i, n - 1) {
    st[0][i] = abs(v[i] - v[i + 1]);
  }

  // st[i][j], length of 2^i and with index from j

  loop1(i, 27) {
    for (int j = 0; j + (1 << i) <= n; j++) { // j is the index
      // gcd first half and second half
      st[i][j] = __gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }

  while (q--) {
    int l, r; cin >> l >> r;
    l--, r--;

    if (l == r) {
      cout << "0 "; continue;
    }

    // extract from sparse table
    int ans = st[0][l];

    // length r-l+1
    // from L to R, cari biner yang cocok
    for (int k = 27; k >= 0; k--) {
      // r-l karena yang dihitung panjang yang terdaftar st, bukan v
      if ((1 << k) <= r - l) {
        ans = __gcd(st[k][l], ans);
        l += 1 << k;
        // l++;
        // cout << st[1 << k][l] << " ";
      }
    }

    cout << ans << " ";
  }
  cout << endl;
  // print all st:
  // for (int i = 0; i <= 26; i++) {
  //   cout << "Level " << i << ": ";
  //   for (int j = 0; j < n; j++) {
  //     cout << st[i][j] << " ";
  //   }
  //   cout << endl;
  // }
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
