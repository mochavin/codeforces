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

vector<int> pre(N, 0);
int cc(int x, int y) {
  int p = pre[y - 1];
  if (x - 2 >= 0) p -= pre[x - 2];
  return x * x - y * y + x + y - p;
}

void solve()
{
  // two pointer
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    pre[i] = v[i];
    if (i) pre[i] += pre[i - 1];
  }

  int ans = 0;
  for (int l = 0, r = n - 1; l <= r;) {
    // int p = pre[r];
    // if (l) p -= pre[l - 1];
    int x = l + 1, y = r + 1;
    cout << x << " " << y << endl;
    ans = max(ans, cc(x, y));
    if (cc(x + 1, y) < cc(x, y - y)) {
      r--;
    }
    else {
      l++;
    }
  }
  cout << ans + pre[n - 1] << endl;
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
