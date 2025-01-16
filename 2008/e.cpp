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
    if (n == 1) {
      cout << 1 << endl; return;
    }
    vector<vector<int>> pre1(n, vector<int>(26, 0));
    vector<vector<int>> pre2(n, vector<int>(26, 0));
    vector<vector<int>> suf1(n, vector<int>(26, 0));
    vector<vector<int>> suf2(n, vector<int>(26, 0));

    loop(i, n) {
      char iki = s[i] - 'a';
      if (i % 2 == 0) {
        loop(j, 26) {
          if (i == 0) {
            pre1[i][j] = (iki == j);
            continue;
          }
          pre1[i][j] = pre1[i - 1][j] + (iki == j);
          pre2[i][j] = pre2[i - 1][j];
        }
      }
      else {
        loop(j, 26) {
          pre1[i][j] = pre1[i - 1][j];
          pre2[i][j] = pre2[i - 1][j] + (iki == j);
        }
      }
    }


    for (int i = n - 1; i >= 0; i--) {
      char iki = s[i] - 'a';

      if (i % 2 == 0) {
        loop(j, 26) {
          if (i == n - 1) {
            suf1[i][j] = (iki == j);
            continue;
          }
          suf1[i][j] = suf1[i + 1][j] + (iki == j);
          suf2[i][j] = suf2[i + 1][j];
        }
      }
      else {
        loop(j, 26) {
          if (i == n - 1) {
            suf2[i][j] = (iki == j);
            continue;
          }
          suf2[i][j] = suf2[i + 1][j] + (iki == j);
          suf1[i][j] = suf1[i + 1][j];
        }
      }
    }

    int ans = M;

    loop(i, n) {
      // remove i-th char
      int mx1 = 0, mx2 = 0;
      if (i == 0) {
        loop(j, 26) {
          mx1 = max(mx1, suf2[i + 1][j]);
          mx2 = max(mx2, suf1[i + 1][j]);
        }
      }
      else if (i != n - 1) {
        loop(j, 26) {
          mx1 = max(mx1, pre1[i - 1][j] + suf2[i + 1][j]);
          mx2 = max(mx2, pre2[i - 1][j] + suf1[i + 1][j]);
        }
      }
      else {
        loop(j, 26) {
          mx1 = max(mx1, pre1[i - 1][j]);
          mx2 = max(mx2, pre2[i - 1][j]);
        }
      }
      ans = min(ans, n - mx1 - mx2);
    }
    cout << ans << endl;
    return;
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
