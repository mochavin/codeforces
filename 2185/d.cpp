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
  int n, m, h; cin >> n >> m >> h;
  vector<int> a(n), t(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i]; t[i] = a[i];
  }

  // last change
  vector<int> ls(n, -1);
  int lastCrash = 0;
  vector<pair<int, int>> b(m);

  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    x--;
    b[i] = { x, y };

    if (ls[x] < lastCrash) {
      t[x] = a[x];
      ls[x] = i;
      if (t[x] + y > h) {
        t[x] = a[x];
        lastCrash = i;
      }
      else {
        t[x] += y;
      }
      continue;
    }

    ls[x] = i;
    if (t[x] + y > h) {
      t[x] = a[x];
      lastCrash = i;
    }
    else {
      t[x] += y;
    }
  }

  for (int i = 0; i < n; i++) {
    if (ls[i] < lastCrash) {
      cout << a[i] << " ";
    }
    else {
      cout << t[i] << " ";
    }
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
