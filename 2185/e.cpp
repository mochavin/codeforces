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
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(n), b(m + 2);
  b[0] = INT_MIN;
  b[m + 1] = INT_MAX;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < m + 1; i++) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  string s; cin >> s;
  map<int, vector<int>> d;
  vector<int> dead(n, 0);
  int ans = n;

  for (int i = 0, j = 0; i < n; i++) {
    while (b[j] < a[i]) j++;
    d[-(a[i] - b[j - 1])].push_back(i);
    d[(b[j] - a[i])].push_back(i);
  }
  int c = 0, r = 0, l = 0;
  for (int i = 0; i < k; i++) {
    if (s[i] == 'L') c--;
    else c++;

    if (c < l) {
      l = c;
      for (auto x : d[c]) {
        if (!dead[x]) ans--;
        dead[x] = 1;
      }
    }
    if (c > r) {
      r = c;
      for (auto x : d[c]) {
        if (!dead[x]) ans--;
        dead[x] = 1;
      }
    }

    cout << ans << " ";
  }
  cout << endl;
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
