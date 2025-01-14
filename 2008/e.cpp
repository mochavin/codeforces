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
  int n; cin >> n;
  string s; cin >> s;
  if (n % 2) {
    // hapus salah satu char
    vector<int> v(26, 0), v2(26, 0);
    loop(i, s.length()) {
      if (i % 2) v2[s[i] - 'a']++;
      else v[s[i] - 'a']++;
    }
    vector<int> a(26, 0), a2(26, 0);
    vector<vector<int>> b(n, vector<int>(26, 0)), b2(n, vector<int>(26, 0));
    loop(i, s.length()) {
      loop(j, 26) {
        if (i == 0) {
          b[i][j] = v2[j];
          b2[i][j] = v[j];
        }
        else {
          b[i][j] = v2[j] - a[j];
          b2[i][j] = v[j] - a2[j];
        }
      }
      int charini = s[i] - 'a';
      if (i % 2) a2[charini]++;
      else a[charini]++;
    }

    loop(i, n) {

    }


  }

  // replace
  // tracking index
  vector<int> v(26, 0), v2(26, 0);
  loop(i, s.length()) {
    if (i % 2) v2[s[i] - 'a']++;
    else v[s[i] - 'a']++;
  }

  int mx1 = 0, mx2 = 0;
  loop(i, 26) {
    mx1 = max(mx1, v[i]);
    mx2 = max(mx2, v2[i]);
  }
  cout << n - mx1 - mx2 << endl;
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
