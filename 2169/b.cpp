#include <bits/stdc++.h>
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
  string s; cin >> s;
  int n = s.size();

  // <>*
  vector<int> c(3, 0);
  for (int i = 0; i < n; i++) {
    if (s[i] == '<') c[0]++;
    else if (s[i] == '>')  c[1]++;
    else c[2]++;

    // ><
    if (c[1] and s[i] == '<') {
      cout << -1 << endl; return;
    }
  }

  if (c[2] > 1) {
    cout << -1 << endl; return;
  }

  // *>>> or <<<*
  if (c[0] == 0 or c[1] == 0) {
    cout << n << endl; return;
  }

  if (c[2] == 0) {
    cout << max(c[0], c[1]) << endl; return;
  }
  else {
    cout << max(c[0], c[1]) + 1 << endl; return;
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
