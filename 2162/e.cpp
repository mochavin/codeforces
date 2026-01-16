#include <bits/stdc++.h>
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 10;

void solve()
{
  int n, k; cin >> n >> k;
  vector<int> v(n), c(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    c[v[i]]++;
  }
  int b = -1;
  for (int i = 1; i <= n; i++) {
    if (c[i] == 0) {
      b = i;
      break;
    }
  }
  if (b == -1) {
    for (int i = 0; i < k; i++) {
      cout << v[i % 3] << " ";
    }
    cout << endl; return;
  }

  vector<int> ans = { b, v[n - 2], v[n - 1] };
  for (int i = 1; i <= n; i++) {
    if (i != b and i != v[n - 1]) {
      ans[1] = i;
    }
  }
  for (int i = 0; i < k; i++) {
    cout << ans[i % 3] << " ";
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
